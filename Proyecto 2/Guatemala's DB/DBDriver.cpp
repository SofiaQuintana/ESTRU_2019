#include "DBDriver.hpp"
#include <sstream>
#include <iostream>

DBDriver::DBDriver(QueryDriver* queries) {
    this -> queries = queries;
    this -> key = 0;
}

/* Recibe como parametro el nombre de la nueva base de datos
 * por lo que, se encarga de revisar que dicha db no exista, 
 * de ser asi crea la base de datos y la agrega a la lista de
 * bases de datos del sistema. */
string DBDriver::createDB(string name) {
    Database* created;
    if(databases.empty()) {
        created = new Database(name);
        databases.push_back(created);
        return  "\n---DB creada con exito---\n";
    } else {
        for(int i = 0; i < databases.size(); i++) {
            Database* aux = databases[i];
            if(aux -> getName() == name) {
                return "\n---Esta base de datos ya existe---\n";
            } 
        }
        created = new Database(name);
        databases.push_back(created);
        return "\n---DB creada con exito---\n";
    }
}

string DBDriver::selectDB(int index) {
    index = index - 1;
    this -> selectedDB = databases[index];
    this -> tables = selectedDB -> getTables();
    return "\nSelecciono la base de datos '" + selectedDB -> getName() + "'\n";
}

Table* DBDriver::getSelectedTable(string name) {
    cout << selectedDB;
    tables = selectedDB -> getTables();
    list<Table*>::iterator it;
    for(it = tables.begin(); it != tables.end(); it++) {
        Table* aux = *it;
        if(aux ->getName() == name) {
            cout << "Se encontro tabla";
            return aux;
        }
    }
    return NULL;
}

string DBDriver::getDatabases() {
    string message;
    int index = 1;
    if(databases.empty()) {
        return "\n---No hay bases de datos, cree una nueva---\n";
    } else {
        for(int i = 0; i < databases.size(); i++) {
            Database* aux = databases[i];
            message += to_string(index) + ". " + aux -> getName() + " \n";
            index++;
        }
        return message;
    }
}

void DBDriver::createTable(vector<string> words) {
    int counter = 1;
    Table* table = new Table(words[0]);
    while(counter < words.size()) {
        createColumn(words[counter], words[counter+1], table);
        counter = counter + 2;
    }
    selectedDB -> addTable(table);
}

string DBDriver::createTable(string query) {
    vector<string> words = queries -> tableWords(query);
    tables = selectedDB -> getTables();
    if(tables.empty()) {
        createTable(words);
        return "\n---Tabla creada con exito---\n";
    } else {
        list<Table*>::iterator it;
        for(it = tables.begin(); it != tables.end(); it++) {
            Table* temp = *it;
            if(temp -> getName() == words[0]) {
                return "\n---Esta tabla ya existe---\n";
            }
        }
        createTable(words);
        return "\n---Tabla creada con exito---\n";
    }
}

void DBDriver::createColumn(string name, string type, Table* table) {
    table -> addColumn(name, type);
}

string DBDriver::insertData(string query) {
    int counter = 1;
    Data* data;
    string message;
    Hashtable* hashTable;
    vector<string> words = queries -> insertWords(query);
    selectedTable = getSelectedTable(words[0]);
    if(selectedTable == NULL) {
        return "\n---Esta tabla no existe---\n";
    } else {
        columns = selectedTable -> getColumns();
        hashTable = selectedTable -> getHash();
        while(counter < words.size()) {
            key++;
            list<Column*>::iterator it;
            for(it = columns.begin(); it != columns.end(); it++) {
                Column* aux = *it;
                stringstream stream(words[counter+2]);
                if(aux -> getName() == words[counter]) {
                   if(aux -> getType() == "string") {
                       data = new Data(words[counter+2],' ',0.0,0, key, aux -> getName());
                   } else if(aux -> getType() == "int") {
                       int number = 0;
                       stream >> number;
                       data = new Data("",' ',0.0,number,key, aux -> getName());
                   } else if(aux -> getType() == "char") {
                       double number;
                       stream >> number;
                       data = new Data("",' ',number,0,key,aux -> getName());
                   } else if(aux -> getType() == "char") {
                       char carac;
                       stream >> carac;
                       data = new Data("",carac,0.0,0,key, aux -> getName());
                   }
                }
            }
            hashTable -> addData(data);
            counter++;
        }
        return "\n---Datos insertados con exito---\n";
    }
}

string DBDriver::getTables() {
    string message;
    int index = 1;
    if(tables.empty()) {
        return "\n---No hay tablas en esta base de datos, cree una nueva---\n";
    } else {
        tables = selectedDB -> getTables();
        list<Table*>::iterator it;
        for(it = tables.begin(); it != tables.end(); it++) {
            Table* aux = *it;
            message += to_string(index) + ". " + aux -> getName() + " \n";
            index++;
        }
        return message;
    }
}
string DBDriver::dataAmountInTable(string table) {
    int amount = 0;
    selectedTable = getSelectedTable(table);
    if(selectedTable == NULL) {
        return "\n----Esta tabla no existe----\n";
    } else {
        Hashtable* map = selectedTable -> getHash();
        list<Data*> data = map -> getList() -> getData("*");
        if(data.empty()) {
            return "\n---No hay datos en esta tabla---\n";
        } else {
            list<Data*>::iterator it;
            for(it = data.begin(); it != data.end(); it++) {
                amount++;
            }
            return "\n--La cantidad de datos en la tabla es: " + to_string(amount) + "\n";
        }
    }
}