#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "List.hpp"
#include <list>
#include <iterator>

using namespace std;

class LinkedList {
    private:
        List *header;
        List *ending;

        void destroyList(List*);

    public:
        LinkedList();
        ~LinkedList();

        void setHeader(List *header);
        void setEnding(List *ending);
        List* getHeader();
        List* getEnding();
        list<AVLTree*> getTrees();
        list<Data*> getData(string);
        void insert(AVLTree *tree, int index);
        void insert(Data* data, int index);
        List* get(int index);
};
#endif /* LINKEDLIST_HPP */