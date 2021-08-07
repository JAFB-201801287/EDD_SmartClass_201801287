#include <iostream>

#include "Lists/CircularDoubleLinkedList.h"
#include "Lists/CircularDoubleLinkedList.cpp"

using namespace std;
//3
int main() 
{
    CircularDoubleLinkedList<int> list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    list.print();

    list.delete_node(1);

    list.print();

    return 0;
}