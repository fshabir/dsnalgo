#pragma once

namespace DS {
	class Queue {
	private:
		int * queueArr;
		int capacity;
		int numElements;
		int front;
		int back;
	public:
		Queue(int);
		bool isEmpty();
		int getFront();
		int getSize();
		bool enqueue(int);
		int dequeue();
		void showQueue();
	};
};