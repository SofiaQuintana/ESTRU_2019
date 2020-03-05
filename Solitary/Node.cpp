#include "Node.hpp"
#include <iostream>

template <typename T>
Node<T>::Node(T value) {
    setData(value);
    setNext(NULL);
} 

//Getters
template <typename T>
T Node<T>::getData() {
    return data;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return this -> next;
}

template <typename T>
Node<T> *Node<T>::getPrevious() {
    return this -> previous;
}

//Setters
template <typename T>
void Node<T>::setPrevious(Node<T> *previousNode) {
    this -> previous = previousNode;
}

template <typename T>
void Node<T>::setNext(Node<T> *nextNode) {
    this -> next = nextNode;
}

template <typename T>
void Node<T>::setData(T value) {
    this -> data = value;
}