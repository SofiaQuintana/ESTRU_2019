#include "LinkedList.hpp"

/* Constructor */
template <typename T>
LinkedList<T>::LinkedList() {
    setHeader(NULL);
    setEnding(NULL);
}

/* Metodos modificadores de nodos */
template <typename T>
void LinkedList<T>::setHeader(Node<T> *head) {
    this -> header = head;
}

template <typename T>
void LinkedList<T>::setEnding(Node<T> *end) {
    this -> ending = end;
}

/* Metodos accesores */
template <typename T>
Node<T>* LinkedList<T>::getHeader() {
    return this -> header;
}

template <typename T>
Node<T>* LinkedList<T>::getEnding() {
    return this -> ending;
}

template <typename T>
void LinkedList<T>::insert(T data) {
    Node<T> *auxiliar = new Node<T>(data);
    if(header ==  NULL) {
        setHeader(auxiliar);
        setEnding(header);
    } else {
        ending -> setRight(auxiliar);
        setEnding(ending -> getRight());
    }
}

/*
template <typename T>
void LinkedList<T>::insert(T data, int index) {
    Node<T> *auxiliar = new Node<T>(data);
    if(header ==  NULL) {
        setHeader(auxiliar);
        header -> setIndex(0);
        setEnding(header);
        ending -> setIndex(1);
    } else {
        auxiliar -> setIndex(ending -> getIndex() + 1);
        ending -> setRight(auxiliar);
        setEnding(ending -> getRight());
    }
} */

template <typename T>
void LinkedList<T>::destroyList(Node<T> *node) {

}

template <typename T>
LinkedList<T>::~LinkedList() {

}