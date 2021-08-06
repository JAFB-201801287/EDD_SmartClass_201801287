#include <iostream>

using namespace::std;

template <class T>
struct DoubleLinkedNode
{
    T element;
	DoubleLinkedNode* after;
	DoubleLinkedNode* before;
};