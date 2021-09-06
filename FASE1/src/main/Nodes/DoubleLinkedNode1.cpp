#include "DoubleLinkedNode1.h"

// CONSTRUCTOR VACIO
template<typename T>
DoubleLinkedNode1<T>::DoubleLinkedNode1()
{
    //element = NULL;
    before = NULL;
    after = NULL;
}

// CONSTRUCTOR CON PARAMENTROS
template<typename T>
DoubleLinkedNode1<T>::DoubleLinkedNode1(T element_)
{
    element = element_;
    after = NULL;
    before = NULL;
}

// DESTRUCTOR
template<typename T>
DoubleLinkedNode1<T>::~DoubleLinkedNode1() {}