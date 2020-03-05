#include "Queue.hpp"

template <typename T>
Queue<T>::Queue() {
    this -> header = NULL;
    this -> ending = NULL;
}

template <typename T>
bool Queue<T>::isEmpty() {
    if(header == NULL) {
        return true;
    }
    return false;
}

template <typename T>
void Queue<T>::enqueue(T data) {
    Node<T> *temporal;
    temporal = new Node<T>(data);
    if(isEmpty()) {
        this->header = temporal;
    } else {
        ending -> setNext(temporal);
    }
    this->ending = temporal;
}

template <typename T>
T Queue<T>::dequeue() {
    if(isEmpty()) {
        throw "Empty queue";
    } else {
        T auxiliar = header -> getData();
        Node<T> *temporal = header;
        header -> setNext(header);
        delete temporal;
        return auxiliar;
    }
}

template <typename T>
T Queue<T>::peek() {
    if(isEmpty()) {
        throw "Empty queue";
    } else {
        return header -> getData();
    }
}

template <typename T>
void Queue<T>::clear() {
    Node<T> *temporal;
    while(!isEmpty()) {
        temporal = this->header;
        header = header -> getNext();
        delete temporal;
    }
}

template <typename T>
Queue<T>::~Queue() {
    clear();
}