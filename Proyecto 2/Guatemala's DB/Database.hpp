#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <string>
#include <bits/stdc++.h>
#include "Table.hpp"

class Database {
    private:
        std::string name;
        std::list<Table*> tables;

    public:
        Database();
        Database(std::string name);
        std::string getName();
        std::list<Table*> getTables();
        void setName(std::string);
        void setTables(std::list<Table*>);
        void addTable(Table*);
        Table* getSelectedTable(std::string);
};
#endif /* DATABASE_HPP */