#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <list>
#include <iterator>
#include "Database.cpp"
#include "Table.cpp"
#include "Column.cpp"
#include "Node.cpp"
#include "Hashtable.cpp"
#include "LinkedList.cpp"
#include "AVLTree.cpp"
#include "Data.cpp"
#include "List.cpp"

using namespace std;

list<Database*> databases;
list<Table*> selectedTables;
Database* selectedDB;
Table* selectedTable;
list<Column*> columns;
Hashtable *table;
int key = 0;

void mainMenu();
Database* selectDB();

void printTables() {
    int temp = 1;
    selectedTables = selectedDB -> getTables();
    list<Table*>::iterator iterator;
    printf("\n---Tablas disponibles---\n");
    for(iterator = selectedTables.begin(); iterator != selectedTables.end(); iterator++) {
        Table* aux = *iterator;
        cout << temp << ". " << aux -> getName() << "\n";
        temp++;
    }
}

Table* selectTable() {
    printTables();
    string selected;
    printf("Insert table name: ");
    cin >> selected;
    list<Table*>::iterator iterator;
    for(iterator = selectedTables.begin(); iterator != selectedTables.end(); iterator++) {
        Table* aux = (*iterator);
        if(aux -> getName() == selected) {
            cout << "Selecciono " << aux -> getName() << "\n";
            return aux;
        }
    }
}
void insertData() {
    key++;
    int option = 0;
    int amount = 0;
    int number;
    string cadena = "";
    char caracter;
    double decimal;
    selectedDB = selectDB();
    selectedTable = selectTable();
    amount = selectedTable -> getColumns().size();
    columns = selectedTable -> getColumns();
    table = selectedTable -> getHash();
    while(amount != 0) {
        list<Column*>::iterator it;
        for(it = columns.begin(); it != columns.end(); it++) {
            Data data;
            Column* column = *it;
            cout << "Ingrese dato para " << column -> getName() << " (" << column ->getType() << "): ";
            if(column -> getType() == "string") {
                cin >> cadena;
                data.setCadena(cadena);
                data.setValue();
                data.setKey(key);
            } else if(column -> getType() == "char") {
                cin >> caracter;
                data.setCaracter(caracter);
                data.setValue();
                data.setKey(key);
            } else if(column -> getType() == "int") {
                cin >> number;
                data.setNumber(number);
                data.setValue();
                data.setKey(key);
            }else if(column -> getType() == "double") {
                cin >> decimal;
                data.setDecimal(decimal);
                data.setValue();
                data.setKey(key);
            }
            table -> addData(data);
            cout << "\n";
        }
    }
    printf("Datos ingresados con exito");
}

void createDB() {
    string name;
    printf("\n Insert DB name: ");
    cin >> name;
    Database* aux = new Database(name);
    databases.push_back(aux);
    printf("\nDB creada con exito.\n");
}

Database* selectDB() {
    string selected;
    printf("Insert DB name: ");
    cin >> selected;
    list<Database*>::iterator iterator;
    for(iterator = databases.begin(); iterator != databases.end(); iterator++) {
        Database* aux = (*iterator);
        if(aux -> getName() == selected) {
            cout << "Selecciono " << aux -> getName() << "\n";
            return aux;
        }
    }
}

void createColumns(int amount, Table* table) {
    string name;
    int type;
    while(amount != 0) {
        printf("\nIngrese nombre de columna: ");
        cin >> name;
        printf("\n----Data type----\n");
        printf("   [1] String\n");
        printf("   [2] Int\n");
        printf("   [3] Double\n");
        printf("   [4] Char\n");
        printf("Insert data type: ");
        cin >> type;
        switch (type) {
        case 1:
            table -> addColumn(name, "string");
        break;
        case 2:
            table -> addColumn(name, "int");
        break;
        case 3:
            table -> addColumn(name, "double");
        break;
        case 4:
            table -> addColumn(name, "char");
        break;
        default:
            printf("Ingrese un tipo valido [1-4]");
        break;
        }
        amount--;
    }
}

void createTable() {
    selectedDB = selectDB();
    string selected;
    int amount;
    printf("Ingrese el nombre de la tabla: ");
    cin >> selected;
    Table* table = new Table(selected);
    printf("\nIngrese cantidad de columnas que tendra: ");
    cin >> amount;
    createColumns(amount, table);
    selectedDB -> addTable(table);
    printf("\nSe creo con exito la tabla\n");
}

void instructionMenu() {
    int option = 1;
    int selected;

    while(option != 0) {
        printf("\n ----Select Instruction----\n");
        printf("   [1] Create Database\n");
        printf("   [2] Create Table\n");
        printf("   [3] Select Data\n");
        printf("   [4] Insert Data\n");
        printf("   [5] Main Menu\n\n");
        printf("Insert Option: ");
        cin >> selected;

        switch (selected)
        {
        case 1:
            createDB();
        break;
        case 2:
            createTable();
        break;
        case 3:
            
        break;
        case 4:
            insertData();
        break;
        case 5:
            option = 0;
        break;
        default:
            cout << "\n Insert a valid option [1-5]";
        break;
        }
    }
}


void mainMenu() {
    key = 0;
    int option = 1;
    int selectedOption;

    while(option != 0) {
        printf("----Guatemala's DB----\n");
        printf("  [1] Instruction \n");
        printf("  [2] Reports \n");
        printf("  [3] DB Graphics \n");
        printf("  [4] Exit \n\n");
        printf("Insert Option: ");

        cin >> selectedOption;

        switch (selectedOption) {
            case 1:
                //Goes to instruction menu
                instructionMenu();
            break;
            case 2:
                //Reports menu
            break;
            case 3:
                //DB graphics menu
            break;
            case 4:
                //Defines ending.
                option = 0; 
            break;
            default:
                cout << "\nInsert a valid option [1 - 4]\n";
            break;
        }
    }
}

int main() {
    mainMenu();
}