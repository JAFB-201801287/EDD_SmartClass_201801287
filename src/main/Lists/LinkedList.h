// COLA

#ifndef LIST_H
#define LIST_H

#include <string>
#include <stdlib.h>

#include "../Nodes/Node.h"
#include "../Nodes/Node.cpp"

using namespace std;

template <class T>

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        void add(T);
        void print();

    private:
        Node<T> *first;
        int index;
};

#endif