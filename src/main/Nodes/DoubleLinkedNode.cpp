#include "DoubleLinkedNode.h"

// CONSTRUCTOR VACIO
template<typename T>
DoubleLinkedNode<T>::DoubleLinkedNode()
{
    //element = NULL;
    before = NULL;
    after = NULL;
}

// CONSTRUCTOR CON PARAMENTROS
template<typename T>
DoubleLinkedNode<T>::DoubleLinkedNode(T element_)
{
    element = element_;
    after = NULL;
    before = NULL;
}

// DESTRUCTOR
template<typename T>
DoubleLinkedNode<T>::~DoubleLinkedNode() {}