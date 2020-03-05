#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include "Node.hpp"

template <class T> class Queue {
    private:
    Node<T> *header;
    Node<T> *ending;

    public:
    Queue();
    void enqueue(T data);
    T dequeue();
    T peek();
    bool isEmpty();
    void clear();

    ~Queue();
};
#endif /*QUEUE_HPP*/