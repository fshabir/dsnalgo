#include "queue.h"
#include <iostream>

using namespace std;
using namespace DS;

Queue::Queue(int capacity) {
	if (capacity >= 0) {
		queueArr = new int[capacity];
	} else {
		queueArr = new int[0];
	}
	this->capacity = capacity;
	numElements = 0;
	front = 0;
	back = -1;
}

bool Queue::isEmpty() {
	if (numElements == 0) {
		return true;
	} else {
		return false;
	}
}

int Queue::getFront() {
	if (!isEmpty()) {
		return queueArr[front];
	}
	return -1;
}

int Queue::getSize() {
	return numElements;
}

int main() {
	Queue queue(10);

	cout << "Size of the queue: " << queue.getSize() << endl;
	return 0;
}