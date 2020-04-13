#ifndef COLUMN_HPP
#define COLUMN_HPP
#include <string>

class Column {
    private:
        std::string name;
        std::string type;

    public:
        Column();
        Column(std::string, std::string);
        void setName(std::string);
        void setType(std::string);
        std::string getName();
        std::string getType();

};
#endif /* COLUMN_HPP */