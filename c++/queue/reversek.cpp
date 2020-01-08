#include "queue.h"
#include "../stack/stack.h"
#include <iostream>

using namespace std;
using namespace DS;

Queue reverse(Queue queue, int k) {
	Stack * st = new Stack(k);
	Queue *temp = new Queue(queue.getSize());

	for (int i=0; i<k; i++) {
		st->push(queue.dequeue());
	}

	while (!st->isEmpty()) {
		temp->enqueue(st->pop());
	}

	while (!queue.isEmpty()) {
		temp->enqueue(queue.dequeue());
	}

	while (!temp->isEmpty()) {
		queue.enqueue(temp->dequeue());
	}

	return queue;
}

Queue reverse2(Queue queue, int k) {
	Stack st(k);
	int count = 0, size = queue.getSize();
	while (count < k) {
		st.push(queue.dequeue());
		count += 1;
	}

	while(!st.isEmpty()) {
		queue.enqueue(st.pop());
	}

	for (int i=0; i < (size - k); i++) {
		queue.enqueue(queue.dequeue());
	}
	return queue;
}

int main() {
	Queue queue(10);
	for (int i=1;i<=10; i++) {
		queue.enqueue(i);
	}

	queue = reverse2(queue, 5);
	cout << "[ ";
	for (int i=1;i<=10; i++) {
		cout << queue.dequeue() << " ";
	}
	cout << "]" << endl;
	return 0;
}