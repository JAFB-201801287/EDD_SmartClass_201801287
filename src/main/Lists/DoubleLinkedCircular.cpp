#include <iostream>

using namespace::std;

#include "../Nodes/DoubleLinkedNode.h"

template <class T>
void add(DoubleLinkedNode<T> *&first, T element_){
	DoubleLinkedNode<T>* new_node = new DoubleLinkedNode<T>();
	new_node->element = element_;
    DoubleLinkedNode<T> *last = NULL;

	if(first==NULL){
		first = new_node;
		last = new_node;
		first->after = first;
		first->before = last;
	}else{
        last = first->before;
		last->after = new_node;
		new_node->before = last;
		new_node->after = first;
		last = new_node;
		first->before = last;
	}
	cout << "\n Dato Ingresado" << endl;
}

template <class T>
void show(DoubleLinkedNode<T> *&list){
	DoubleLinkedNode<T> *current = new DoubleLinkedNode<T>();
    DoubleLinkedNode<T> *first = list;
    //DoubleLinkedNode<T> *last = NULL;
	current = first;

	if(first!=NULL){
		do{
			cout << "\n " << current->element; 
			current = current->after;
		}while(current!=first);
		
	}else{
		cout << "\n La list se Encuentra Vacia\n\n";
	}
}
