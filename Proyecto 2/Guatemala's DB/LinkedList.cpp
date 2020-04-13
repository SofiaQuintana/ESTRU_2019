#include "LinkedList.hpp"

/* Constructor */
LinkedList::LinkedList() {
    setHeader(NULL);
    setEnding(NULL);
}

/* Metodos modificadores de nodos */
void LinkedList::setHeader(List *head) {
    this -> header = head;
}

void LinkedList::setEnding(List *end) {
    this -> ending = end;
}

/* Metodos accesores */
List* LinkedList::getHeader() {
    return this -> header;
}

List* LinkedList::getEnding() {
    return this -> ending;
}

/* Para insertar arboles */
void LinkedList::insert(AVLTree *tree, int index) {
    List *auxiliar = new List(tree, index);
    if(header ==  NULL) {
        setHeader(auxiliar);
        setEnding(header);
    } else {
        ending -> setRight(auxiliar);
        setEnding(ending -> getRight());
    }
}

void LinkedList::insert(Data data, int index) {
    int counter = 0;
    for(List *temp = this -> header; temp != NULL; temp = temp -> getRight()) {
        counter++;
        if(counter == index) {
            AVLTree* tree = temp -> getTree();
            tree -> insert(data);
        }
    }
} 

void LinkedList::destroyList(List *List) {

}

LinkedList::~LinkedList() {

}