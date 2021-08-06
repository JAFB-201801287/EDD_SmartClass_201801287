#include <iostream>

using namespace::std;

template <class T>
struct TailNode
{
    T element;
	TailNode* after;
	TailNode* before;
};