#include "Hashtable.hpp"

Hashtable::Hashtable() {
    setAmount(5);
    initList();
}

int Hashtable::hash(Data* data) {
    int value = data -> getValue();
    int index = value % getAmount();
    return index;
}

void Hashtable::initList() {
    this -> list = new LinkedList();
    for(int i = 0; i < getAmount(); i++) {
        AVLTree *auxiliar = new AVLTree();
        this -> list ->insert(auxiliar,i);
    }
}

void Hashtable::addData(Data* data) {
    this -> list -> insert(data, hash(data));
}

void Hashtable::setAmount(int amount) {
    this -> nodeAmount = amount;
}

int Hashtable::getAmount() {
    return this -> nodeAmount;
}

LinkedList* Hashtable::getList() {
    return this -> list;
}