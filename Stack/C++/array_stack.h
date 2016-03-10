#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

template <class T>
class array_stack {
private:
	int stackPointer;
	int size;
	T * arr;

public:
	array_stack();
	array_stack(int);
	~array_stack();
	void push(T);
	T& pop();
	T& peek();

};

template <class T>
array_stack<T>::array_stack() {
	stackPointer = 0;
	size = 10;
	arr = new T[size];
}

template <class T>
array_stack<T>::array_stack(int size) {
	stackPointer = 0;
	this->size = size;
	arr = new T[size];
}

template <class T>
array_stack<T>::~array_stack() {
	delete arr;
}

template <class T>
void array_stack<T>::push(T data) {
	stackPointer++;
	arr[stackPointer] = data;
}

template <class T>
T& array_stack<T>::pop() {
	if (stackPointer > 0) {
		stackPointer--;
		return arr[stackPointer + 1];
	}
	throw 1;
}

template <class T>
T& array_stack<T>::peek() {
	return arr[stackPointer];
}


#endif

