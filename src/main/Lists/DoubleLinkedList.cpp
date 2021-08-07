#include "DoubleLinkedList.h"

using namespace std;

// CONSTRUCTOR VACIO
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    index = 0;
    first = NULL;
}

// DESTRUCTOR
template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {}

// INSERTA NODO
template<typename T>
void DoubleLinkedList<T>::add(T element_)
{
    DoubleLinkedNode<T> *new_node = new DoubleLinkedNode<T> (element_);
    DoubleLinkedNode<T> *temp = first;
    DoubleLinkedNode<T> *last = NULL;

    if(!first) {
        first = new_node;
        first->after = NULL;
        first->before = NULL;
    } else {
        while (temp != NULL)
        {
            last = temp;
            temp = temp->after;
        }

        last->after = new_node;
        new_node->before = last;
        new_node->after = NULL;
        last = new_node;
    }
    index++;
}

//IMPRIME LA INFORMACION
template<typename T>
void DoubleLinkedList<T>::print()
{
    DoubleLinkedNode<T> *current = new DoubleLinkedNode<T>();
    DoubleLinkedNode<T> *temp = first;
	current = first;

	if(first != NULL){
		while(current != NULL){
            if(!current->before) 
            {
                cout << "\n " << "VACIO <- " << current->element << " -> " << current->after->element << endl;
            } else if (!current->after)
            {
                cout << "\n " << current->before->element << " <- " << current->element << " -> VACIO " << endl;
            } else {
                cout << "\n " << current->before->element << " <- " << current->element << " -> " << current->after->element << endl;
            }
            
			 
			current = current->after;
		}
	}else{
		cout << "\nLISTA VACIA\n\n";
	}
    cout << endl << endl;
}

// ELIMINA NODO POR ELEMENTO
template<typename T>
void DoubleLinkedList<T>::delete_node(T element_)
{
    DoubleLinkedNode<T>* current = new DoubleLinkedNode<T>();
    current = first;
    DoubleLinkedNode<T>* before = new DoubleLinkedNode<T>();
    before = NULL;
    bool found = false;
    DoubleLinkedNode<T> *temp = first;
    DoubleLinkedNode<T> *last = NULL;

    while (temp != NULL)
    {
        last = temp;
        temp = temp->after;
    }

    if(first != NULL) 
    {
        while (current != NULL && !found)
        {
            if(current->element == element_) 
            {
                if(current == first) 
                {
                    first = first->after;
                    first->before = NULL;
                } else if (current == last)
                {
                    before->after = NULL;
                    last = before;
                } else {
                    before->after = current->after;
                    current->after->before = before;
                }
                found = true;
                index--;
            }
            before = current;
            current = current->after;
        }
        
        if (found)
        {
            cout << "ELEMENTO ELIMINADO DE LA LISTA" << endl;
        }
        
    } else {
        cout << "LISTA VACIA" << endl;
    }
}

// ELIMINAR POR INDICE
template<typename T>
void DoubleLinkedList<T>::delete_id(int id)
{
    DoubleLinkedNode<T> *temp = first;
    DoubleLinkedNode<T> *temp1 = temp->after;
 
    if (id < 1 || id > index) {
        cout << "Fuera de rango " << endl;
    } else if (id == 1) {
        first = temp->after;
        first->before = NULL;
        cout << "ELEMENTO ELIMINADO DE LA LISTA" << endl;
    } else {
        for (int i = 2; i <= id; i++) {
            if (i == id) {
                DoubleLinkedNode<T> *aux_node = temp1;
                temp->after = temp1->after;
                delete aux_node;
                index--;
                cout << "ELEMENTO ELIMINADO DE LA LISTA" << endl;
            }
            temp = temp->after;
            temp1 = temp1->after;
        }
    }
}
