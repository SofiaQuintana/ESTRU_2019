#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "Node.hpp"

template <class T> class AVLTree {
    private:
        Node<T> *root;

        Node<T>* insert(Node<T> *node, T data);
        void destroyTree(Node<T> *leaf);
        Node<T>* search(Node<T> *leaf, T data);

    public:
        AVLTree();
        ~AVLTree();

        Node<T>* getRoot();
        void setRoot(Node<T> *root);

        void insert(T data);
        Node<T>* search(T data);
        void destroyTree();
        int height(Node<T>* leaf);
        int difference(Node<T>* leaf);
        Node<T>* balance(Node<T>* leaf);
        Node<T>* rightRotation(Node<T>* leaf);
        Node<T>* leftRotation(Node<T>* leaf);
        Node<T>* doubleRightRotation(Node<T>* leaf);
        Node<T>* doubleLeftRotation(Node<T>* leaf);
};
#endif /* AVLTREE_HPP */