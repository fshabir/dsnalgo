#include <iostream>

using namespace std;

class Stack {
private:
	int capacity;
	int * arr;
	int top1;
	int top2;
public:
	Stack(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		top1 = -1;
		top2 = capacity;
	}

	void push1(int val) {
		if (top1 < (top2 - 1)) {
			arr[++top1] = val;
		} else {
			cout << "Stack is full" << endl;
		}
	}

	void push2(int val) {
		if (top2 > (top1 + 1)) {
			arr[--top2] = val;
		} else {
			cout << "Stack is full" << endl;
		}
	}

	int pop1() {
		if (top1 != -1) {
			return arr[top1--];
		}
		return -1;
	}

	int pop2 () {
		if (top2 != capacity) {
			return arr[top2++];
		}
		return -1;
	}
};

int main() {
	Stack twoStacks(6);
	twoStacks.push1(1);
	twoStacks.push1(2);
	twoStacks.push1(3);

	twoStacks.push2(4);
	twoStacks.push2(5);
	twoStacks.push2(6);

	cout << "[ ";
	for (int i=0; i<3; i++) {
		cout << twoStacks.pop1() << " ";
	}

	for (int i=0; i<3; i++) {
		cout << twoStacks.pop2() << " ";
	}
	cout << "]" << endl;

	twoStacks.push1(1);
	twoStacks.push1(2);
	twoStacks.push1(3);
	twoStacks.push1(4);

	twoStacks.push2(5);
	twoStacks.push2(6);
	twoStacks.push2(7);

	cout << "[ ";
	for (int i=0; i<3; i++) {
		cout << twoStacks.pop1() << " ";
	}

	for (int i=0; i<3; i++) {
		cout << twoStacks.pop2() << " ";
	}
	cout << "]" << endl;
	return 0;
}