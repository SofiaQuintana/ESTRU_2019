#ifndef DBDRIVER_HPP
#define DBDRIVER_HPP
#include "Database.hpp"
#include "QueryDriver.hpp"
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class DBDriver {
    private:
        QueryDriver* queries;
        Database* selectedDB;
        vector<Database*> databases;
        Table* selectedTable;
        list<Table*> tables;
        Column* selectedColumn; 
        list<Column*> columns;
        void createTable(vector<string>);
        int key;

    public:
        DBDriver(QueryDriver*);
        string selectDB(int);
        Table* getSelectedTable(string);
        Column* getSelectedColumn(string);
        string createDB(string);
        string createTable(string);
        void createColumn(string, string, Table*);
        string getDatabases();
        string getTables();
        string insertData(string);
        string dataAmountInTable(string);
};
#endif /* DBDRIVER_HPP */
