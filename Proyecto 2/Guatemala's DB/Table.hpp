#ifndef TABLE_HPP
#define TABLE_HPP
#include <string>
#include <list>
#include "Hashtable.hpp"
#include "Column.hpp"

class Table {
    private:
        std::string name;
        std::list<Column*> columns;
        Hashtable *hashmap;

    public:
        Table();
        Table(std::string name);
        void addColumn(std::string, std::string);
        void addTuple(Data data);
        void setName(std::string);
        std::string getName();
        std::list<Column*> getColumns();
        Hashtable* getHash();
};
#endif /* TABLE_HPP */