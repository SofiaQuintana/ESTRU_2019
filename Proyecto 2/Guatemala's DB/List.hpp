#ifndef LIST_HPP
#define LIST_HPP
#include "AVLTree.hpp"

class List {
    private:
        List *left;
        List *right;
        int index;
        AVLTree *tree;

    public:
        List(AVLTree*,int);
        List* getLeft();
        List* getRight();
        int getIndex();
        AVLTree* getTree();
        void setLeft(List*);
        void setRight(List*);
        void setIndex(int);
}; 
#endif /* LIST_HPP */