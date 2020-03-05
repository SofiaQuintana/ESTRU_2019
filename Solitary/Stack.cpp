#include "Stack.hpp"
#include <iostream>

template <typename T>
Stack<T>::Stack() {
    this -> header = NULL;
}

template <typename T>
bool Stack<T>::isEmpty() {
    if(header == NULL) {
        return true;
    }
    return false;
}

template <typename T>
void Stack<T>::push(T value) {
    Node<T> *auxiliar;
    auxiliar = new Node<T>(value);
    auxiliar -> setNext(header);
    header = auxiliar;
}

template <typename T>
T Stack<T>::pop() {
    if(isEmpty()) {
        throw "Empty stack";
    }
    Node<T> *temporal = this -> header;
    header = temporal -> getNext();
    T auxiliar = temporal -> getData();
    delete(temporal);
    return auxiliar;
}

template <typename T>
T Stack<T>::peek() {
    if(isEmpty()) {
        throw "Empty stack";
    }
    return header -> getData();
}

template <typename T>
void Stack<T>::clear() {
    Node<T> *node;
    while(!isEmpty()) {
        node = this -> header;
        header = header -> getNext();
        delete node;
    }
}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

