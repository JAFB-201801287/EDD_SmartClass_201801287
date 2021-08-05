#include <iostream>
#include "List/Simple.cpp"

using namespace std;

int main() 
{
    
    SimpleList<int> *s = NULL;

    add(1,s, 5);
    add(2,s, 55);
    add(3,s, 555);
    add(4,s, 5555);
    add(5,s, 1);
    add(6,s, 2);

    show(s);

    return 0;
}