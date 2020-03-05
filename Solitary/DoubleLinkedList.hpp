#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include "Node.hpp"

template <class T> class DoubleLinkedList {
    private:
    Node<T> *header;
    Node<T> *ending;
    int length;

    public:
    DoubleLinkedList();
    void insert(int index, T value);
    void insertAtFront(T value);
    void insertAtEnding(T value);
    T get(int index);
    int size();
    bool isEmpty();
    void clear();
    void remove(int index);
    ~DoubleLinkedList();
};
#endif /*DOUBLELINKEDLIST_HPP*/