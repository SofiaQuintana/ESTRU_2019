#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include "Node.hpp"

template <class T> class Stack {
    private:
    Node<T> *header;

    public:
    Stack(); //Constructor
    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
    void clear();

    ~Stack(); //Desctructor
};
#endif /*STACK_HPP*/