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

bool Queue::enqueue(int data) {
	if (numElements < capacity) {
		back += 1;
		queueArr[back] = data;
		numElements += 1;
		return true;
	} else {
		return false;
	}
}

int Queue::dequeue() {
	if (!isEmpty()) {
		int temp = queueArr[front];
		for (int i=0; i < numElements; i++) {
			queueArr[i] = queueArr[i+1];
		}
		back -= 1;
		numElements -= 1;
		return temp;
	}
	return -1;
}

void Queue::showQueue() {
	cout << "Queue: [ ";
	for (int i=front; i <= back; i++) {
		cout << queueArr[i] << " ";
	}
	cout << "]" << endl;
}

int main() {
	Queue queue(10);

	cout << "Size of the queue: " << queue.getSize() << endl;
	queue.enqueue(10);
	queue.enqueue(15);
	queue.enqueue(17);
	queue.enqueue(19);
	cout << "Size of the queue: " << queue.getSize() << endl;
	queue.showQueue();
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << "Size of the queue: " << queue.getSize() << endl;
	queue.showQueue();
	return 0;
}