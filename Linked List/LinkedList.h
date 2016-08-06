#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>

template <class T>
class Node {

public:
	Node<T> * next;
	T data;
	Node(T d): data(d) {
		next = NULL;
	}

};

template <class T>
class LinkedList {

private:
	Node<T> * head;
public:
	Node<T> * current;
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList &list);
	void add(T data);
	T& get();
	T& get(T data);
	void remove();
	void remove(T);
	void reset();
	void operator<<(T data);
	void operator++(int);
	void setCurrent(Node<T> * c);
};

template <class T>
void LinkedList<T>::setCurrent(Node<T> * c) {
	this->current = c;
}

template <class T>
LinkedList<T>::LinkedList() {
	this->head = NULL;
	this->current = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (head != NULL) {
		this->remove();
	}
}

template <class T>
void LinkedList<T>::reset() {
	current = head;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList &list) {

	this->head = NULL;
	this->current = NULL;
	Node<T> * temp = list.head;

	if (list.head != NULL) {
		this->add(list.head->data);
	}

	while (temp != NULL && temp->next != NULL) {
		this->add(temp->next->data);
		temp = temp->next;
	}

	this->reset();

}

template <class T>
void LinkedList<T>::add(T data) {
	Node<T> * node = new Node<T>(data);

	this->reset();

	while (current != NULL && current->next != NULL) {
		current = current->next;
	}

	if (current == NULL && head == NULL) {
		head = node;
		current = head;
	}
	else if (current != NULL) {
		current->next = node;
	}

}

template <class T>
void LinkedList<T>::remove() {
	this->reset();

	while (current != NULL && current->next != NULL && current->next->next != NULL) {
		current = current->next;
	}

	if (current == NULL) {
		return;
	}
	else if (current != NULL && current->next == NULL) {
		delete current;
		head = NULL;
		current = head;
	}
	else if (current != NULL && current->next != NULL) {
		delete current->next;
		current->next = NULL;
	}

}

template <class T>
void LinkedList<T>::remove(T data) {
	this->reset();


	while (current != NULL && current->next != NULL && current->next->next != NULL) {
		if (current->data == data) {
			head = current->next;
			delete current;
			current = head;
		}
		else if (current->next->data == data) {
			Node<T> * node = current->next->next;
			delete current->next;
			current->next = node;
			break;
		}
		current = current->next;
	}

	if (current == NULL) {
		return;
	}
	else if (current != NULL && current->next == NULL) {
		if (current->data == data) {
			delete current;
			head = NULL;
			current = head;
		}
	}
	else if (current != NULL && current->next != NULL) {
		if (current->data == data) {
			head = current->next;
			delete current;
			current = head;
		}
		else if (current->next->data == data) {
			delete current->next;
			current->next = NULL;
		}
	}




}

template <class T>
T& LinkedList<T>::get() {
	Node<T> * temp = head;

	while (temp != NULL && temp->next != NULL) {
		temp = temp->next;
	}

	return temp->data;
}

template <class T>
T& LinkedList<T>::get(T myData) {
	Node<T> * temp = head;

	while (temp != NULL && temp->next != NULL) {
		if (temp->data == myData) {
			return temp->data;
		}
		temp = temp->next;
	}
	if (temp != NULL && temp->data == myData) {
		return temp->data;
	}
	return myData;

}

template <class T>
void LinkedList<T>::operator<<(T data) {
	this->add(data);
}

template <class T>
void LinkedList<T>::operator++(int) {
	if (current != NULL && current->next != NULL) {
		current = current->next;
	}
}

#endif
