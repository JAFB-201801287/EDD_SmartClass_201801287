#ifndef LIST_H
#define LIST_H

#include <string>
#include <stdlib.h>

#include "../Nodes/DoubleLinkedNode.h"
#include "../Nodes/DoubleLinkedNode.cpp"

using namespace std;

template <class T>

class DoubleLinkedList
{
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();

        void add(T);
        void print();
        void delete_node(T);
        void delete_id(int);

    private:
        DoubleLinkedNode<T> *first;
        int index;
};

#endif