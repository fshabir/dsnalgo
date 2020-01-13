#include <iostream>
#include <stack>

using namespace std;

class myStack {
private:
	stack<int> *st;
	int _min;
public:
	myStack(int size) {
		st = new stack<int>();
	}

	void push (int val) {
		if (st->empty() || val < _min) {
			_min = val;
		}
		st->push(val);
	}

	int pop() {
		int top = - 1;
		stack<int> temp;
		if (!st->empty() && st->top() == _min) {
			top = st->top();
			st->pop();

			while (!st->empty()) {
				temp.push(st->top());
				st->pop();
			}

			while (!temp.empty()) {
				st->push(temp.top());
				temp.pop();
			}
		} else if (!st->empty()){
			top = st->top();
			st->pop();
		}

		return top;
	}

	int min() {
		return st->empty() ? -1 : _min;
	}
};


int main() {
	myStack st(10);
	st.push(4);
	st.push(2);
	st.push(5);

	cout << "Min is: " << st.min() << endl;
	return 0;
}