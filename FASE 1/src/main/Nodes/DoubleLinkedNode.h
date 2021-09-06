#ifndef DOUBLELINKEDNODE_H
#define DOUBLELINKEDNODE_H

#include <iostream>

using namespace std;

template <class T>
class DoubleLinkedNode
{
    public:
        DoubleLinkedNode();
        DoubleLinkedNode(T);
        ~DoubleLinkedNode();

        DoubleLinkedNode *before;
        DoubleLinkedNode *after;
        T element;
};

#endif