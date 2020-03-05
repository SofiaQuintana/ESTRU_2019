#include <iostream>
#ifndef NODE_HPP
#define NODE_HPP

template <class T> class Node {
    private:
        T data;
        Node<T> *next;
        Node<T> *previous;

    public:
        Node(T data);
        Node<T>* getNext();
        Node<T>* getPrevious();
        void setNext(Node<T>* next);
        void setPrevious(Node<T>* previous);
        T getData();
        void setData(T); 
};
#endif /* NODE_HPP */