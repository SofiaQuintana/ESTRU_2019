#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "Node.hpp"

template <class T> class LinkedList {
    private:
        Node<T> *header;
        Node<T> *ending;

        void destroyList(Node<T>*);

    public:
        LinkedList();
        ~LinkedList();

        void setHeader(Node<T> *header);
        void setEnding(Node<T> *ending);
        Node<T>* getHeader();
        Node<T>* getEnding();

        void insert(T data);
        void insert(T data, int index);
        Node<T>* get(int index);
};
#endif /* LINKEDLIST_HPP */