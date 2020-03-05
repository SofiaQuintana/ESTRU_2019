#include "DoubleLinkedList.hpp"
#include <iostream>

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    this -> header = ending = NULL;
    this -> length = 0;
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty() {
    if(header == NULL && ending == NULL) {
        return true;
    }
    return false;
}

template <typename T>
int DoubleLinkedList<T>::size() {
    if(isEmpty()) {
        return length = 0;
    } else {
        this-> length = 1;
        for (Node<T>* node = this-> header; node != ending; node = node->getNext()) {
            this -> length++;
        }
        return length;
        
    }
}

template <typename T>
void DoubleLinkedList<T>::insertAtFront(T value) {
    Node<T>* temporal = new Node<T>(value);
    if(isEmpty()) {
        this -> header = temporal;
        this -> ending = header;
    } else {
        temporal -> setNext(this->header);
        header -> setPrevious(temporal);
        header = temporal;
    }
}

template <typename T>
void DoubleLinkedList<T>::insertAtEnding(T value) {
    Node<T>* temporal = new Node<T>(value);   
    if(isEmpty()) {
        this ->header = temporal;
        this ->ending = header;
    } else {
        temporal -> setPrevious(this-> ending);
        ending -> setNext(temporal);
        ending = temporal;
    }
}

template <typename T>
void DoubleLinkedList<T>::insert(int index, T value) {
    if (index == this -> size()) {
        this -> insertAtEnding(value);
    } else {
        if(!isEmpty()) {
            if(index >= size() || index < 0) {
            } else {
                int temporal = 0;
                for(Node<T>* node = this->header; node != NULL; node = node->getNext()) {
                    if(temporal == index) {
                        Node<T>* auxiliar = new Node<T>(value);
                        node -> getPrevious() -> setNext(auxiliar);
                        auxiliar -> setPrevious(node->getPrevious());
                        auxiliar -> setNext(node);
                        node -> setPrevious(auxiliar);
                        break;
                    }
                temporal++;
                }
            }
        }
    }
}

template <typename T>
T DoubleLinkedList<T>::get(int index) {
    length = size();
    if(!isEmpty()) {
        if(index >= length || index < 0) {
            throw "Index out of bounds";
        } else {
            int temporal = 0;
            for(Node<T>* node = this->header; node != NULL; node = node->getNext()) {
                if(temporal == index) {
                    return node -> getData();
                }
                temporal++;
            }
        }
    }
    return (T) NULL;
}

template <typename T>
void DoubleLinkedList<T>::clear() {
    Node<T> *node;
    while(!isEmpty()) {
        node = header;
        header = header -> getNext();
        node ->getNext() -> setPrevious(NULL);
        delete node;
    }
    header = ending = NULL;
}

template <typename T>
void DoubleLinkedList<T>::remove(int index){
    if(!isEmpty()){
        int actualIndex = 0;
        for(Node<T>* node = this->header; node != NULL; node = node->getNext()){
            if(actualIndex == index){
                delete(node);
                break;
            }   
        actualIndex++;
        }
    }
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    clear();
}

