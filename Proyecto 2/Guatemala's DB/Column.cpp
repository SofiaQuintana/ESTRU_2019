#include "Column.hpp"

using namespace std; 

/* Constructor, recibe el tipo y el nomnbre de la columna. */
Column::Column(string type, string name) {
    setType(type);
    setName(name);
}

Column::Column() {
    setType("");
    setName("");
}
/* Modificadores (Setters) */
void Column::setName(string name) {
    this -> name = name;
}

void Column::setType(string type) {
    this -> type = type;
}

/* Accesores (Getters) */
string Column::getName() {
    return this -> name;
}

string Column::getType() {
    return this -> type;
} 