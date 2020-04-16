#ifndef NODE_HPP
#define NODE_HPP
#include "Data.hpp"

class Node {
    private:
        Data *data;;
        Node *left;
        Node *right;
        int index;

    public:
        Node(Data*);
        Node* getLeft();
        Node* getRight();
        int getIndex();
        Data* getData();
        void setLeft(Node*);
        void setRight(Node*);
        void setData(Data*);
        void setIndex(int);
}; 
#endif /* NODE_HPP */