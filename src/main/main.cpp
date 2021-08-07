#include <iostream>

#include "Lists/DoubleLinkedList.h"
#include "Lists/DoubleLinkedList.cpp"

using namespace std;
//0
int main() 
{
    DoubleLinkedList<int> list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    list.print();

    list.delete_id(1);
    list.delete_node(5);

    return 0;
}