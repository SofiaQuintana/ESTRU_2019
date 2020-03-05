#ifndef CARD_HPP
#define CARD_HPP
#include <string>
using namespace std;

class Card {
    private:
    string value; //Valor de la carta
    string type; //Diamantes, Treboles, Espadas o Corazones.
    int color; //1 = Rojo ; 0 = Negro.
    bool hidden; //Muestra el reverso o la carta.

    public:
    Card();
    Card(string value, string type, int color, bool hidden);
    string getType();
    int getColor();
    string getValue();
    void setColor(int color);
    void setValue(string value);
    void setType(string type);
    bool isHidden();
    void setHidden(bool hidden);
};
#endif /*CARD_HPP*/