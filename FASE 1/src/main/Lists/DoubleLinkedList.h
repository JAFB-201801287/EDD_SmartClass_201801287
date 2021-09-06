#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <string>
#include <stdlib.h>

#include "../Nodes/DoubleLinkedNode1.h"
#include "../Nodes/DoubleLinkedNode1.cpp"

using namespace std;

template <class T>

class DoubleLinkedList
{
    protected:
        DoubleLinkedList();
        ~DoubleLinkedList();

        void add(T);
        void print();
        void delete_node(T);
        void delete_id(int);

        DoubleLinkedNode1<T> *first;
        int index;
};

#endif