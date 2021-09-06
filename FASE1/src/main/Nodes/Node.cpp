#include "Node.h"

// CONSTRUCTOR VACIO
template<typename T>
Node<T>::Node()
{
    //element = NULL;
    after = NULL;
}

// CONSTRUCTOR CON PARAMENTROS
template<typename T>
Node<T>::Node(T element_)
{
    element = element_;
    after = NULL;
}

// DESTRUCTOR
template<typename T>
Node<T>::~Node() {}