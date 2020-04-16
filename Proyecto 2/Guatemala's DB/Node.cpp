#include "Node.hpp"

/* Constructores */
Node::Node(Data* data) {
    setData(data);
    setLeft(NULL);
    setRight(NULL);
}

/* Metodos accesores (Getters) */
Data* Node::getData() {
    return this -> data;
}

Node* Node::getLeft() {
    return this -> left;
}

Node* Node::getRight() {
    return this -> right;
}

int Node::getIndex() {
    return this -> index;
}

/* Metodos modificadores (Setters) */
void Node::setData(Data* data) {
    this -> data = data;
}

void Node::setLeft(Node *left) {
    this -> left = left;
}

void Node::setRight(Node *right) {
    this -> right = right;
}

void Node::setIndex(int index) {
    this -> index = index;
}
 