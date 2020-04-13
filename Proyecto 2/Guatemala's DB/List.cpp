#include "List.hpp"

/* Constructores */
List::List(AVLTree *tree, int index) {
    this -> tree = tree;
    setLeft(NULL);
    setRight(NULL);
    setIndex(index);
}

/* Metodos accesores (Getters) */
List* List::getLeft() {
    return this -> left;
}

List* List::getRight() {
    return this -> right;
}

int List::getIndex() {
    return this -> index;
}

AVLTree* List::getTree() {
    return this -> tree;
}

/* Metodos modificadores (Setters) */
void List::setLeft(List *left) {
    this -> left = left;
}

void List::setRight(List *right) {
    this -> right = right;
}

void List::setIndex(int index) {
    this -> index = index;
}
 