#include "LinkedList.hpp"
#include <iterator>

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

void LinkedList::insert(Data* data, int index) {
    int counter = 0;
    for(List *temp = this -> header; temp != NULL; temp = temp -> getRight()) {
        counter++;
        if(counter == index) {
            AVLTree* tree = temp -> getTree();
            tree -> insert(data);
        }
    }
} 

list<AVLTree*> LinkedList::getTrees() {
    list<AVLTree*> trees;
    for(List *temp = header; temp != NULL; temp = temp -> getRight()) {
        trees.push_back(temp -> getTree());
    }
    return trees;
}

list<Data*> LinkedList::getData(string selection) {
    list<AVLTree*> trees = getTrees();
    list<Data*> data;
    list<Data*> temp;
    list<AVLTree*>::iterator it;
    list<Data*>::iterator iterator;
    for(it = trees.begin(); it != trees.end(); it++) {
        AVLTree* tree = *it;
        temp = tree -> search(selection);
        for(iterator = temp.begin(); iterator != temp.end(); iterator++) {
            Data* aux = *iterator;
            data.push_back(aux);
        }
    }
}

void LinkedList::destroyList(List *List) {

}

LinkedList::~LinkedList() {

}