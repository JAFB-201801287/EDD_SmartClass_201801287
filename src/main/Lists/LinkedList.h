// COLA

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <stdlib.h>

#include "../Nodes/Node.h"
#include "../Nodes/Node.cpp"

using namespace std;

template <class T>

class LinkedList
{
    protected:
        LinkedList();
        ~LinkedList();

        void add(T);
        void print();


        Node<T> *first;
        int index;
};

#endif