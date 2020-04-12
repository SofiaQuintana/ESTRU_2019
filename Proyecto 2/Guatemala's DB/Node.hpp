#include <iostream>
#ifndef NODE_HPP
#define NODE_HPP

template <class T> class Node {
    private:
        T data;
        Node<T> *left;
        Node<T> *right;
        int index;

    public:
        Node(T data);
        Node(T data, int index);
        Node<T>* getLeft();
        Node<T>* getRight();
        int getIndex();

        T getData();
        void setLeft(Node<T> *left);
        void setRight(Node<T> *right);
        void setData(T data);
        void setIndex(int);
}; 
#endif /* NODE_HPP */