#include "Table.hpp"

using namespace std;

Table::Table() {
    setName("");
}

Table::Table(string name) {
    setName(name);
    this -> hashmap = new Hashtable();
}

void Table::addColumn(string name, string type) {
    Column *column = new Column(type, name);
    this -> columns.push_back(column);
}

void Table::addTuple(Data* data) {
    this -> hashmap -> addData(data);
}

string Table::getName() {
    return this -> name;
}

void Table::setName(string name) {
    this -> name = name;
}

list<Column*> Table::getColumns() {
    return this -> columns;
}

Hashtable* Table::getHash() {
    return this -> hashmap;
}