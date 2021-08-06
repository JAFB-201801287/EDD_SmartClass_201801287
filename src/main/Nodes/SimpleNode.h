#include <iostream>

using namespace::std;

template <class T>
struct SimpleNode
{
    T element;
	SimpleNode* after;
	SimpleNode* before;
};