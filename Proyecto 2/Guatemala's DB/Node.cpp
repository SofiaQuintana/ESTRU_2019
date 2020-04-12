#include "Node.hpp"
#include <iostream>

/* Constructores */
template <typename T>
Node<T>::Node(T data) {
    setData(data);
    setLeft(NULL);
    setRight(NULL);
}

template <typename T>
Node<T>::Node(T data, int index) {
    setData(data);
    setLeft(NULL);
    setRight(NULL);
    setIndex(index);
}

/* Metodos accesores (Getters) */
template <typename T>
T Node<T>::getData() {
    return this -> data;
}

template <typename T>
Node<T>* Node<T>::getLeft() {
    return this -> left;
}

template <typename T>
Node<T>* Node<T>::getRight() {
    return this -> right;
}

template <typename T>
int Node<T>::getIndex() {
    return this -> index;
}

/* Metodos modificadores (Setters) */
template <typename T>
void Node<T>::setData(T data) {
    this -> data = data;
}

template <typename T>
void Node<T>::setLeft(Node<T> *left) {
    this -> left = left;
}

template <typename T>
void Node<T>::setRight(Node<T> *right) {
    this -> right = right;
}

template <typename T>
void Node<T>::setIndex(int index) {
    this -> index = index;
}
 