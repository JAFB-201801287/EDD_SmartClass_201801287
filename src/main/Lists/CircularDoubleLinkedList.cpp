#include "CircularDoubleLinkedList.h"

using namespace std;

// CONSTRUCTOR VACIO
template<typename T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList()
{
    index = 0;
    first = NULL;
}

// DESTRUCTOR
template<typename T>
CircularDoubleLinkedList<T>::~CircularDoubleLinkedList() {}

// INSERTA NODO
template<typename T>
void CircularDoubleLinkedList<T>::add(T element_)
{
    DoubleLinkedNode<T> *new_node = new DoubleLinkedNode<T> (element_);
    DoubleLinkedNode<T> *last = NULL;
    DoubleLinkedNode<T> *current = new DoubleLinkedNode<T>();

    if(!first) {
        first = new_node;
        last = new_node;
        first->after = first;
        first->before = first;
    } else {
        /*do
        {
            last = current;
            current = current->after;
        } while (current!=first);
        
        last->after = new_node;
        new_node->before = last;
        new_node->after = first;
        last = new_node;
        first->before = last;*/

        last = first->before;
        last->after = new_node;
        new_node->before = last;
        new_node->after = first;
        last = new_node;
        first->before = last;
    }
    index++;
}

//IMPRIME LA INFORMACION
template<typename T>
void CircularDoubleLinkedList<T>::print()
{
    DoubleLinkedNode<T> *current = new DoubleLinkedNode<T>();
    DoubleLinkedNode<T> *temp = first;
	current = first;

	if(first != NULL){
		do{
			cout << "\n " << current->before->element << " <- " << current->element << " -> " << current->after->element;
			current = current->after;
		} while(current!=first);
	}else{
		cout << "\nLISTA VACIA\n\n";
	}
    cout << endl << endl;
}

//IMPRIME LA INFORMACION POSTERIOR
template<typename T>
void CircularDoubleLinkedList<T>::print_pos()
{
    DoubleLinkedNode<T> *current = new DoubleLinkedNode<T>();
    DoubleLinkedNode<T> *temp = first;
	current = first;

	if(first != NULL){
		do{
            current = current->before;
			cout << "\n " << current->element; 
		} while(current!=first);
	}else{
		cout << "\nLISTA VACIA\n\n";
	}
    cout << endl << endl;
}

// ELIMINA NODO POR ELEMENTO
template<typename T>
void CircularDoubleLinkedList<T>::delete_node(T element_)
{
    DoubleLinkedNode<T> *temp = first;
    DoubleLinkedNode<T> *temp1 = first->after;
    DoubleLinkedNode<T> *last = first->before;
 
    int cont = 0;
 
    if (first->element == element_) {
        if(index == 1) 
        {
            first = NULL;
        } else {
            first = temp1;
            last->after = temp1;
            first->before = last;
        }
        cont++;
    } else {
        while (temp1) {
            if (temp1->element == element_) {
                DoubleLinkedNode<T> *aux_node1 = temp1;
                DoubleLinkedNode<T> *aux_node2 = temp;
                temp->after = temp1->after;
                temp->after->before = aux_node2;
                delete aux_node1;
                cont++;
                index--;
            }
            temp = temp->after;
            temp1 = temp1->after;
        }
    }
 
    if (cont == 0) {
        cout << "NO EXISTE EL ELEMENTO " << endl;
    }
}


