#include "AVLTree.hpp"
#include <algorithm>
#define pow2(n) (1 << (n))

using namespace std;

/* Constructor */
template <typename T>
AVLTree<T>::AVLTree() {
    //Sin raiz, es decir arbol vacio.
    setRoot(NULL); 
}

/* Accesor a la raiz del arbol AVL */
template <typename T>
Node<T>* AVLTree<T>::getRoot() {
    return this -> root;
}

/* Modificador de raiz del arbol AVL */
template <typename T>
void AVLTree<T>::setRoot(Node<T> *root) {
    this -> root = root;
}

/* Elimina cada una de las hojas del arbol */
template <typename T>
void AVLTree<T>::destroyTree(Node<T> *leaf) {
    if(leaf != NULL) {
        destroyTree(leaf -> getLeft());
        destroyTree(leaf -> getRight());
        delete leaf;
    }
}

/* Llama al metodo encargado de eliminar cada hoja del arbol, 
 * pasandole como parametro la raiz del mismo. */
template <typename T>
void AVLTree<T>::destroyTree() {
    destroyTree(getRoot());
}

/* Destructor */
template <typename T>
AVLTree<T>::~AVLTree() {
    destroyTree();
}

/* Calcula la altura del arbol AVL dado */
template <typename T>
int AVLTree<T>::height(Node<T> *leaf) {
    int height = 0;
    if(leaf != NULL) {
        int leftHeight = height(leaf -> getLeft());
        int rightHeight = height(leaf -> getRight());
        int maxHeight = max(leftHeight, rightHeight);
        height = maxHeight + 1;
    }
    return height;
}

/* Calcula el factor de equilibrio entre c/u de los sub arboles. */
template <typename T>
int AVLTree<T>::difference(Node<T> *leaf) {
    int leftHeight = height(leaf -> getLeft());
    int rightHeight = height(leaf -> getRight());
    int balanceFactor = leftHeight - rightHeight;
    return balanceFactor;
}

/* Combinacion de rotacion a la derecha, seguida de rotacion a la derecha */
template <typename T>
Node<T>* AVLTree<T>::rightRotation(Node<T> *parent) {
    Node<T> *auxiliar;
    auxiliar = parent -> getRight();
    parent -> setRight(auxiliar -> getLeft());
    auxiliar -> setLeft(parent);
    return auxiliar;
}

/* Combinacion de rotacion a la izquierda, seguida de rotacion a la izquierda */
template <typename T>
Node<T>* AVLTree<T>::leftRotation(Node<T> *parent) {
    Node<T> *auxiliar;
    auxiliar = parent -> getLeft();
    parent -> setLeft(auxiliar -> getRight());
    auxiliar -> setRight(parent);
    return auxiliar;
}

/* Combinacion de rotacion a la izquierda, seguida de rotacion a la derecha */
template <typename T>
Node<T>* AVLTree<T>::doubleLeftRotation(Node<T> *parent) {
    Node<T> *auxiliar;
    auxiliar = parent -> getLeft();
    parent -> setLeft(rightRotation(auxiliar));
    return leftRotation(parent);
}

/* Combinacion de rotacion a la derecha, seguida de rotacion a la izquierda */
template <typename T>
Node<T>* AVLTree<T>::doubleRightRotation(Node<T> *parent) {
    Node<T> *auxiliar;
    auxiliar = parent -> getRight();
    parent -> setRight(leftRotation(auxiliar));
    return rightRotation(parent);
}

/* Realiza el balance del arbol AVL, mediante las rotaciones correspondientes
 * haciendo uso del factor de equilibrio entre sub arboles. */
template <typename T>
Node<T>* AVLTree<T>::balance(Node<T> *leaf) {
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

template <typename T>
Node<T>* AVLTree<T>::insert(Node<T> *leaf, T data) {
    if(leaf == NULL) {
        leaf = new Node<T>(data);
        return leaf;
    } else if( data <  leaf -> getData()) {
        leaf -> setLeft(insert(leaf -> getLeft(), data));
        leaf = balance(leaf);
    } else if( data >= leaf -> getData()) {
        leaf -> setRight(insert(leaf -> getRight(), data));
        leaf = balance(leaf);
    }
    return leaf;
}

template <typename T>
void AVLTree<T>::insert(T data) {
    if(this -> root != NULL) {
        setRoot(insert(getRoot(), data));
    } else {
        this -> root = new Node<T>(data);
    }
}

template <typename T>
Node<T>* AVLTree<T>::search(Node<T> *parent, T data) {
    if(leaf != NULL) {
        if(data == parent -> getData()) 
            return parent;
        if(data < parent -> getData())
            return search(parent -> getLeft(), data);
        else 
            return search(parent -> getRight(), data);
    } else {
        return NULL;
    }
}

template <typename T>
Node<T>* AVLTree<T>::search(T data) {
    return search(getRoot(), data);
}
