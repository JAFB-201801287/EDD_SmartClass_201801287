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

// Eliminar todos los Nodos
template<typename T>
void Node<T>::delete_all()
{
    if (after)
        after->delete_all();
    delete this;
}

// Imprimir un Nodo
template<typename T>
void Node<T>::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << after << endl;
    cout << element << "-> ";
}

template<typename T>
Node<T>::~Node() {}