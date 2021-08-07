#include "Node.h"

// Constructor por defecto
template<typename T>
Node<T>::Node()
{
    element = NULL;
    after = NULL;
}

// Constructor por parámetro
template<typename T>
Node<T>::Node(T element_)
{
    element = element_;
    after = NULL;
}

template<typename T>
Node<T>::~Node() {}