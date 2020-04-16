#include "AVLTree.hpp"
#include <algorithm>
#define pow2(n) (1 << (n))

/* Constructor */
AVLTree::AVLTree() {
    //Sin raiz, es decir arbol vacio.
    setRoot(NULL); 
}

/* Accesor a la raiz del arbol AVL */
Node* AVLTree::getRoot() {
    return this -> root;
}

/* Modificador de raiz del arbol AVL */
void AVLTree::setRoot(Node *root) {
    this -> root = root;
}

/* Elimina cada una de las hojas del arbol */
void AVLTree::destroyTree(Node *leaf) {
    if(leaf != NULL) {
        destroyTree(leaf -> getLeft());
        destroyTree(leaf -> getRight());
        delete leaf;
    }
}

/* Llama al metodo encargado de eliminar cada hoja del arbol, 
 * pasandole como parametro la raiz del mismo. */
void AVLTree::destroyTree() {
    destroyTree(getRoot());
}

/* Destructor */
AVLTree::~AVLTree() {
    destroyTree();
}

/* Calcula la altura del arbol AVL dado */
int AVLTree::height(Node* leaf) {
    int altura = 0;
    if(leaf != NULL) {
        int leftHeight = height(leaf -> getLeft());
        int rightHeight = height(leaf -> getRight());
        int maxHeight = max(leftHeight, rightHeight);
        altura = maxHeight + 1;
    }
    return altura;
}

/* Calcula el factor de equilibrio entre c/u de los sub arboles. */
int AVLTree::difference(Node *leaf) {
    int leftHeight = height(leaf -> getLeft());
    int rightHeight = height(leaf -> getRight());
    int balanceFactor = leftHeight - rightHeight;
    return balanceFactor;
}

/* Combinacion de rotacion a la derecha, seguida de rotacion a la derecha */
Node* AVLTree::rightRotation(Node *parent) {
    Node *auxiliar;
    auxiliar = parent -> getRight();
    parent -> setRight(auxiliar -> getLeft());
    auxiliar -> setLeft(parent);
    return auxiliar;
}

/* Combinacion de rotacion a la izquierda, seguida de rotacion a la izquierda */
Node* AVLTree::leftRotation(Node *parent) {
    Node *auxiliar;
    auxiliar = parent -> getLeft();
    parent -> setLeft(auxiliar -> getRight());
    auxiliar -> setRight(parent);
    return auxiliar;
}

/* Combinacion de rotacion a la izquierda, seguida de rotacion a la derecha */
Node* AVLTree::doubleLeftRotation(Node *parent) {
    Node *auxiliar;
    auxiliar = parent -> getLeft();
    parent -> setLeft(rightRotation(auxiliar));
    return leftRotation(parent);
}

/* Combinacion de rotacion a la derecha, seguida de rotacion a la izquierda */
Node* AVLTree::doubleRightRotation(Node *parent) {
    Node *auxiliar;
    auxiliar = parent -> getRight();
    parent -> setRight(leftRotation(auxiliar));
    return rightRotation(parent);
}

/* Realiza el balance del arbol AVL, mediante las rotaciones correspondientes
 * haciendo uso del factor de equilibrio entre sub arboles. */
Node* AVLTree::balance(Node *leaf) {
    int balanceFactor = difference(leaf);
    if(balanceFactor > 1) {
        if(difference(leaf -> getLeft()) > 0)
            leaf = leftRotation(leaf);
        else 
            leaf = doubleLeftRotation(leaf);
    } else if(balanceFactor < -1) {
        if(difference(leaf -> getRight()) > 0) 
            leaf = doubleRightRotation(leaf);
        else 
            leaf = rightRotation(leaf);
    }
    return leaf;
}

Node* AVLTree::insert(Node *leaf, Data* data) {
    double value = data -> getValue();
    if(leaf == NULL) {
        leaf = new Node(data);
        return leaf;
    } else if( value <  leaf -> getData() -> getValue()) {
        leaf -> setLeft(insert(leaf -> getLeft(), data));
        leaf = balance(leaf);
    } else if( value >= leaf -> getData() -> getValue()) {
        leaf -> setRight(insert(leaf -> getRight(), data));
        leaf = balance(leaf);
    }
    return leaf;
}

void AVLTree::insert(Data* data) {
    if(this -> root != NULL) {
        setRoot(insert(getRoot(), data));
    } else {
        this -> root = new Node(data);
    }
}

list<Data*> AVLTree::search(Node *parent, string selection, list<Data*> data) {
    if(parent != NULL) {
        if(selection == "*") {
            data.push_back(parent -> getData());
            search(parent -> getLeft(), selection, data);
            search(parent -> getRight(), selection, data);
        } else if(selection == parent -> getData() -> getColumn()) 
            data.push_back(parent -> getData());
            search(parent -> getLeft(), selection, data);
            search(parent -> getRight(), selection, data);
    } else {
        return data;
    }
    return data;
}


list<Data*> AVLTree::search(string selection) {
    list<Data*> data;
    return search(getRoot(), selection, data);
}
