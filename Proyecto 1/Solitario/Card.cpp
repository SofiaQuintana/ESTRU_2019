#include "Card.hpp"
#include <string.h>

using namespace std;

Card::Card() {
    this -> value = "";
    this -> type = "";
    this -> color = 0;
    this -> hidden = true;
}

Card::Card(string value, string type, int color, bool hidden) {
    this -> value = value;
    this -> type = type;
    this -> color = color;
    this -> hidden = hidden;
}

string Card::getType() {
    return type;
}

int Card::getColor() {
    return color;
}

string Card::getValue() {
    return value;
}

bool Card::isHidden() {
    return hidden;
}

void Card::setValue(string value) {
    this -> value = value;
}

void Card::setType(string type) {
    this -> type = type;
}

void Card::setHidden(bool hidden) {
    this -> hidden = hidden;
}

void Card::setColor(int color) {
    this -> color = color;
}
