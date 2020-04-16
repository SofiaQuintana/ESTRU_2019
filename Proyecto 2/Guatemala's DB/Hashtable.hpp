#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "LinkedList.hpp"

class Hashtable {
    private:
        LinkedList *list;
        int nodeAmount;

    public:
        Hashtable();
        ~Hashtable();
        int hash(Data* data);
        LinkedList* getList();
        void initList();
        void addData(Data* data);
        void setAmount(int);
        int getAmount();
};
#endif /* HASHTABLE_HPP */