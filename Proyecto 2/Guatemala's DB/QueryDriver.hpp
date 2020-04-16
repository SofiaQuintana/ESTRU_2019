#ifndef QUERYDRIVER_HPP
#define QUERYDRIVER_HPP
#include "LinkedList.hpp"
#include <vector>
#include <string>

using namespace std;

class QueryDriver {
    private:
        int initial;
        int found;
        string splitted;
        string::size_type position;

        string replace(string);
        vector<string> split(string);

    public:
        QueryDriver();
        vector<string> tableWords(string);
        vector<string> insertWords(string);
        vector<string> selectWords(string);
        vector<string> removeWords(string, string, string, string);
        ~QueryDriver();

};

#endif /* QUERYDRIVER_HPP */
