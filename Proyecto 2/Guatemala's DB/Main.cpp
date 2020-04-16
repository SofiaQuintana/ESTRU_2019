#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <list>
#include <vector>
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
#include "QueryDriver.cpp"
#include "DBDriver.cpp"

using namespace std;

QueryDriver* queries;
DBDriver* driver;

void tableReport() {
    string selected;
    string message;
    printf("\n---Seleccione la tabla---\n");
    message = driver -> getTables();
    cout << message;
    printf("\nIngrese el nombre de la tabla seleccionada: \n");
    cin >> selected;
    cout << selected;
    message = driver -> dataAmountInTable(selected);
    cout << message;
}

void selectDB() {
    int selected;
    string message;
    printf("\n----DB's disponibles----\n");
    message = driver -> getDatabases();
    cout << message;
    printf("\nIngrese numero de DB: ");
    cin >> selected;
    message = driver -> selectDB(selected);
    cout << message;
}
 
void createTable() {
    string selected;
    string message;
    printf("\n----Ingrese CREATE Query----\n");
    getline(cin, selected, ';');
    message = driver -> createTable(selected);
    cout << message;
}

void insertData() {
    string query;
    string message;
    printf("\n----Ingrese INSERT Query----\n");
    getline(cin, query, ';');
    message = driver -> insertData(query);
    cout << message;
}
 
void createDB() {
    string message;
    string name;
    printf("\nInsert DB name: ");
    cin >> name;
    message = driver -> createDB(name);
    cout << message;
}

void reportsMenu() {
    int option = 1;
    int selected;
    string message;

    while(option != 0) {
        printf("\n ----Select Report----\n");
        printf("   [1] Cantidad de datos en todas las bases de datos.\n");
        printf("   [2] Cantidad de datos en tabla.\n");
        printf("   [3] Cantidad de columnas de un mismo tipo de dato en tabla.\n");
        printf("   [4] Cantidad de columnas de todas las bases de datos.\n");
        printf("   [5] Main Menu\n\n");
        printf("Insert Option: ");
        cin >> selected;

        switch (selected) {
        case 1: tableReport(); break;
        case 2: ; break;
        case 3: ; break;
        case 4:               break;
        case 5: option = 0; break;
        default: cout << "\n Insert a valid option [1-5]"; break;
        }
    }

}

void instructionMenu() {
    int option = 1;
    int selected;
    string message;

    while(option != 0) {
        printf("\n ----Select Instruction----\n");
        printf("   [1] Create Database\n");
        printf("   [2] Select Database\n");
        printf("   [3] Create Table\n");
        printf("   [4] Select Data\n");
        printf("   [5] Insert Data\n");
        printf("   [6] Main Menu\n\n");
        printf("Insert Option: ");
        cin >> selected;

        switch (selected) {
        case 1: createDB(); break;
        case 2: selectDB(); break;
        case 3: createTable(); break;
        case 4:               break;
        case 5: insertData(); break;
        case 6: option = 0; break;
        default: cout << "\n Insert a valid option [1-6]"; break;
        }
    }
}

void mainMenu() {
    int option = 1;
    int selectedOption;
    queries = new QueryDriver();
    driver = new DBDriver(queries);

    while(option != 0) {
        printf("----Guatemala's DB----\n");
        printf("  [1] Query \n");
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
                //Goes to reports menu
                reportsMenu();
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