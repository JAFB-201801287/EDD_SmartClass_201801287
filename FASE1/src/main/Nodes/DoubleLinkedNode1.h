#ifndef DOUBLELINKEDNODE1_H
#define DOUBLELINKEDNODE1_H

#include <iostream>

using namespace std;

template <class T>
class DoubleLinkedNode1
{
    public:
        DoubleLinkedNode1();
        DoubleLinkedNode1(T);
        ~DoubleLinkedNode1();

        DoubleLinkedNode1 *before;
        DoubleLinkedNode1 *after;
        T element;
};

#endif