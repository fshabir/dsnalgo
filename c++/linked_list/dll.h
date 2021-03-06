#pragma once

#include <string>

namespace LinkedList {
	class DLL {
	private:
		struct Node {
			int data;
			Node * next;
			Node * prev;
		};

		Node * head;
		Node * tail;

	public:
		DLL();

		void insert(int data);
		void append(int data);
		std::string getList();
		void reverse();
		void reverse2();
		void insertLoop();
		bool detectLoop();
		int findMiddle();
	};
}