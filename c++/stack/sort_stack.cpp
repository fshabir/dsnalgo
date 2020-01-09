#include <iostream>
#include "stack.h"

using namespace std;
using namespace DS;

Stack* sortStack(Stack * stack, int size) {
	Stack * st1 = new Stack(size);
	Stack * st2 = new Stack(size);
	int max, temp;

	while (!stack->isEmpty()) {
		st1->push(stack->pop());
	}

	while (!st1->isEmpty()) {
		max = st1->pop();
		st1->push(max); // Peeking at the top of stack

		while (!st1->isEmpty()) {
			temp = st1->pop();
			if (temp > max) {
				max = temp;
			}
			st2->push(temp);
		}
		stack->push(max);

		while (!st2->isEmpty()) {
			temp = st2->pop();
			if (temp != max) {
				st1->push(temp);
			}
		}
	}
	return stack;
}

int main() {
	Stack *st = new Stack(10);
	st->push(23);
	st->push(60);
	st->push(12);
	st->push(42);
	st->push(4);
	st->push(97);
	st->push(2);

	st = sortStack(st, 10);
	for (int i=0; i<7; i++) {
		cout << "Popped: " << st->pop() << endl;
	}
	return 0;
}