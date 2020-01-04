#include "stack.h"
#include <iostream>

using namespace std;
using namespace DS;

Stack::Stack(int capacity) {
	if (capacity > 1)
		stackArr = new int[capacity];
	else
		stackArr = new int[0];
	numElements = 0;
	this->capacity = capacity;
	top = -1;
}

bool Stack::isEmpty() {
	if (numElements == 0) {
		return true;
	} else {
		return false;
	}
}

int Stack::getTop() {
	if (!isEmpty()) {
		return stackArr[top];
	}
	return -1;
}

int Stack::getSize() {
	return numElements;
}

bool Stack::push(int data) {
	if (numElements < capacity) {
		stackArr[++top] = data;
		numElements += 1;
		return true;
	}
	return false;
}

int Stack::pop() {
	if (!isEmpty()) {
		numElements -= 1;
		return stackArr[top--];
	}
	return -1;
}

void Stack::showStack() {
	if (!isEmpty()) {
		cout << "Stack: [ ";
		for (int i=top; i >= 0; i--) {
			cout << stackArr[i] << " ";
		}
		cout << "]" << endl;
	}
}

Stack::~Stack() {
	delete [] stackArr;
}

int main () {
	Stack stack(10);
	cout << "Size of stack is: " << stack.getSize() << endl;

	stack.push(9);
	stack.push(8);
	stack.push(10);
	cout << "Size of stack is: " << stack.getSize() << endl;
	stack.showStack(); 

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << "Size of stack is: " << stack.getSize() << endl;
	stack.showStack();
	return 0;
}