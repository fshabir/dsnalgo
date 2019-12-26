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

		bool insert(int data);		
		std::string getList();
		std::string reverse();
	};
}