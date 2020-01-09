#include <iostream>
#include "../stack/stack.h"

using namespace std;
using namespace DS;

class Queue {
private:
	Stack * st1;
	Stack * st2;
	int capacity;
	int numElements;
public:
	Queue(int size) {
		capacity = size;
		st1 = new Stack(size);
		st2 = new Stack(size);
		numElements = 0;
	}

	void Enqueue(int val) {
		if (numElements < capacity) {
			st1->push(val);
			numElements++;
		}
	}

	int Dequeue() {
		if (numElements > 0) {
			while (!st1->isEmpty()) {
				st2->push(st1->pop());
			}
			int res = st2->pop();

			while (!st2->isEmpty()) {
				st1->push(st2->pop());
			}
			numElements--;
			return res;
		}
		return -1;
	}
};


int main() {

	Queue q(5);
	q.Enqueue(4);
	q.Enqueue(5);
	q.Enqueue(6);
	q.Enqueue(7);
	q.Enqueue(8);
	q.Enqueue(9);

	for (int i=0; i<10; i++) {
		cout << "Dequeued: " << q.Dequeue() << endl;
	}
	return 0;
}