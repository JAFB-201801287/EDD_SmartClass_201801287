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
    DoubleLinkedNode1<T> *new_node = new DoubleLinkedNode1<T> (element_);
    DoubleLinkedNode1<T> *temp = first;
    DoubleLinkedNode1<T> *last = NULL;
    DoubleLinkedNode1<T> empty_node;

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
    DoubleLinkedNode1<T> *current = new DoubleLinkedNode1<T>();
    DoubleLinkedNode1<T> *temp = first;
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
		cout << "\n LISTA VACIA\n\n";
	}
    cout << endl << endl;
}

// ELIMINA NODO POR ELEMENTO
template<typename T>
void DoubleLinkedList<T>::delete_node(T element_)
{
    DoubleLinkedNode1<T>* current = new DoubleLinkedNode1<T>();
    current = first;
    DoubleLinkedNode1<T>* before = new DoubleLinkedNode1<T>();
    before = NULL;
    bool found = false;
    DoubleLinkedNode1<T> *temp = first;
    DoubleLinkedNode1<T> *last = NULL;

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
    DoubleLinkedNode1<T> *temp = first;
    DoubleLinkedNode1<T> *temp1 = temp->after;
 
    if (id < 1 || id > index) {
        cout << "Fuera de rango " << endl;
    } else if (id == 1) {
        first = temp->after;
        first->before = NULL;
        cout << "ELEMENTO ELIMINADO DE LA LISTA" << endl;
    } else {
        for (int i = 2; i <= id; i++) {
            if (i == id) {
                DoubleLinkedNode1<T> *aux_node = temp1;
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
