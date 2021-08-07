#ifndef LIST_H
#define LIST_H

#include <string>
#include <stdlib.h>

#include "../Nodes/DoubleLinkedNode.h"
#include "../Nodes/DoubleLinkedNode.cpp"

using namespace std;

template <class T>

class CircularDoubleLinkedList
{
    public:
        CircularDoubleLinkedList();
        ~CircularDoubleLinkedList();

        void add(T);
        void print();
        void print_pos();
        void delete_node(T);

    private:
        DoubleLinkedNode<T> *first;
        int index;
};

#endif