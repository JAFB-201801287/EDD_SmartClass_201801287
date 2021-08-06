#include <iostream>

using namespace::std;

template <class T>
struct TailNode
{
    T element;
	DoubleLinkedCircularList* after;
	DoubleLinkedCircularList* before;
};