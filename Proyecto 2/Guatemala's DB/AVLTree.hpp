#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "Node.hpp"
#include "Data.hpp"

class AVLTree {
    private:
        Node* root;
        Node* insert(Node *node, Data data);
        void destroyTree(Node *leaf);
        Node* search(Node *leaf, Data data);

    public:
        AVLTree();
        ~AVLTree();

        Node* getRoot();
        void setRoot(Node *root);

        void insert(Data data);
        Node* search(Data data);
        void destroyTree();
        int height(Node* leaf);
        int difference(Node* leaf);
        Node* balance(Node* leaf);
        Node* rightRotation(Node* leaf);
        Node* leftRotation(Node* leaf);
        Node* doubleRightRotation(Node* leaf);
        Node* doubleLeftRotation(Node* leaf);
};
#endif /* AVLTREE_HPP */