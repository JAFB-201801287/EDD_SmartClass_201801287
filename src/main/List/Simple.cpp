#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
struct SimpleList
{
    int index = 0;
    T element;
    struct SimpleList *after;
};

template <class T>
void add(int index,SimpleList<T> *&list, T element_) 
{
    SimpleList<T> *new_node = new SimpleList<T>();
    new_node -> element = element_;

    SimpleList<T> *aux_node1 = list;
    SimpleList<T> *aux_node2;

    while ((aux_node1 != NULL) && (aux_node1->index < index))
    {
        aux_node2 = aux_node1;
        aux_node1 = aux_node1->after;
    }

    if(list == aux_node1) {
        list = new_node;
    } else {
        aux_node2->after = new_node;
    }

    new_node->after = aux_node1;    
}

template <class T>
void show(SimpleList<T> *list) 
{
    SimpleList<T> *current = new SimpleList<T>();
    current = list;

    while (current != NULL)
    {
        cout << current->element << " -> ";
        current = current->after;  
    }
    
}