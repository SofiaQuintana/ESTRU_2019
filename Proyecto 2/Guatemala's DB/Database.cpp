#include "Database.hpp"
#include <iterator>
using namespace std;

/* Constructor */
Database::Database(string name) {
    setName(name);
}

Database::Database() {
    setName("");
}

/* Accesores (Getters) */
string Database::getName() {
    return this -> name;
}

list<Table*> Database::getTables() {
    return this -> tables;
}

/* Modificadores (Setters) */
void Database::setName(string name) {
    this -> name = name;
}

void Database::setTables(list<Table*> tables) {
    this -> tables = tables;
}

/* Agrega una tabla a la lista de tablas de una DB. */
void Database::addTable(Table* table) {
    this -> tables.push_back(table);
}

Table* Database::getSelectedTable(string name) {
    list<Table*>::iterator iterator;
    for(iterator = tables.begin(); iterator != tables.end(); iterator++) {
        Table* table = *iterator;
        if(table -> getName() == name) {
            return table;
        }
    }
}