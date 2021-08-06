#include <iostream>

using namespace::std;

template <class T>
struct SimpleNode
{
    T element;
	DoubleLinkedCircularList* after;
	DoubleLinkedCircularList* before;
};