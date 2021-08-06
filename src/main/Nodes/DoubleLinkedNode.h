#include <iostream>

using namespace::std;

template <class T>
struct DoubleLinkedNode
{
    T element;
	DoubleLinkedCircularList* after;
	DoubleLinkedCircularList* before;
};