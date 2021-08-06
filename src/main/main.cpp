#include <iostream>

using namespace std;

#include "Lists/DoubleLinkedCircular.cpp"

int main() 
{
    //PREUBA
    DoubleLinkedNode<int> *n = NULL;

    for (int i = 1; i < 6; i++)
    {
        add(n, i);
    }
    cout << "\n\n LISTA DOBLEMENTE ENLAZADA CIRCULAR\n";
    show(n);
    //cout << " PRUEBA 8" << endl;

    return 0;
}