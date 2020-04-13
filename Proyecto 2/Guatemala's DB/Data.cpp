#include "Data.hpp"
#include <numeric>

using namespace std;

Data::Data() {
    setCadena("");
    setCaracter(' ');
    setDecimal(0);
    setNumber(0);
    setKey(0);
    setColumn("");
}

Data::Data(string cadena, char caracter, double decimal, int number, int key, string column) {
    setCadena(cadena);
    setCaracter(caracter);
    setDecimal(decimal);
    setNumber(number);
    setKey(key);
    setColumn(column);
}

void Data::setCadena(string cadena) {
    this -> cadena = cadena;
}

void Data::setCaracter(char caracter) {
    this -> caracter = caracter;
}

void Data::setDecimal(double decimal) {
    this -> decimal = decimal;
}

void Data::setNumber(int number) {
    this -> number = number;
}

void Data::setKey(int key) {
    this -> key = key;
}

void Data::setColumn(string column) {
    this -> column = column;
}

void Data::setValue() {
    if(cadena != "") {
        this -> value = accumulate(next(cadena.begin()), cadena.end(), static_cast<int>(cadena.at(0)),
                                 [](int a, char b) { 
                                    return a + static_cast<int>(b);
                                 });
    } else if(number != 0) {
        this -> value = number;
    } else if(decimal != 0) {
        this -> value = number;
    } else if(caracter != ' ') {
        this -> value = (double) caracter;
    }
}

double Data::getValue() {
    return this -> value;
}

string Data::getColumn() {
    return this -> column;
}