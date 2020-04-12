#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "LinkedList.hpp"

template <class T> class Hashtable {
    private:
        LinkedList<T> list;
    
    public:
        Hashtable();
        ~Hashtable();
        void hash(String type, T data);
        int getStringValue(String data);
        int getCharValue(char data);
};
#endif /* HASHTABLE_HPP */