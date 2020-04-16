#include "DBDriver.hpp"

DBDriver::DBDriver(QueryDriver* queries) {
    this -> queries = queries;
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
    tables = selectedDB -> getTables();
    list<Table*>::iterator it;
    for(it = tables.begin(); it != tables.end(); it++) {
        Table* aux = *it;
        if(aux ->getName() == name) {
            return aux;
        }
    }
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
    string message;
    vector<string> words = queries -> insertWords(query);
    for(int i = 0; i < words.size(); i++) {
        message += words[i] + ", ";
    }
    selectedTable = getSelectedTable(words[0]);
    return message;
}