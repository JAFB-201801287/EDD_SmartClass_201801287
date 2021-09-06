// COLA
#include "LinkedList.h"

using namespace std;

// CONSTRUCTOR VACIO
template<typename T>
LinkedList<T>::LinkedList()
{
    index = 0;
    first = NULL;
}

// DESTRUCTOR
template<typename T>
LinkedList<T>::~LinkedList() {}

// AGREGAR ELEMENTO A LISTA
template<typename T>
void LinkedList<T>::add(T element_)
{
    Node<T> *new_node = new Node<T> (element_);
    Node<T> *temp = first;

    if (!first) {
        first = new_node;
        first->after = NULL;
    } else {
        while (temp->after != NULL) {
            temp = temp->after;
        }
        new_node->after = NULL;
        temp->after = new_node;
    }
    index++;
}

// IMPRESION DE DATOS
template<typename T>
void LinkedList<T>::print()
{
    Node<T> *temp = first;
    if (!first) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->after) cout << "NULL";
                temp = temp->after;
        }
  }
  cout << endl << endl;
}