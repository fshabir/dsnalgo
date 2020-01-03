#pragma once

namespace DS {
	class Stack {
	private:
		int * stackArr;
		int capacity;
		int numElements;
		int top;
	public:
		Stack(int);
		bool isEmpty();
		int getTop();
		int getSize();
		bool push(int);
		int pop();
		void showStack();
		~Stack();
	};
};