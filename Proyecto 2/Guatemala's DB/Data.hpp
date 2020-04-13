#ifndef DATA_HPP
#define DATA_HPP
#include <string>

class Data {
    private:
        int number;
        char caracter;
        std::string cadena;
        double decimal;
        double value;
        int key;
        std::string column;

    public:
        Data();
        Data(std::string, char, double, int, int, std::string);
        void setNumber(int);
        void setCaracter(char);
        void setCadena(std::string);
        void setDecimal(double);
        void setValue();
        void setKey(int);
        void setColumn(std::string);
        int getNumber();
        char getCaracter();
        std::string getCadena();
        double getDecimal();
        double getValue();
        int getKey();
        std::string getColumn();
};
#endif /* DATA_HPP */