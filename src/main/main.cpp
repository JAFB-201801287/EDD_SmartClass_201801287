#include <iostream>

#include "Lists/LinkedList.h"
#include "Lists/LinkedList.cpp"

using namespace std;

int main() 
{
    LinkedList<int> list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    list.print();

    return 0;
}