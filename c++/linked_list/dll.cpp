#include "dll.h"
#include <iostream>

using namespace std;

namespace LinkedList {
	DLL::DLL() {
		head = nullptr;
		tail = nullptr;
	}

	void DLL::insert(int data) {
		Node * node = new Node;
		node->data = data;
		node->next = nullptr;
		node->prev = nullptr;

		if (head) {
			node->next = head;
			head->prev = node;
		}		

		if (!head) {
			tail = node;
		}
		head = node;
	}

	void DLL::append(int data) {
		Node * node = new Node;
		node->data = data;
		node->prev = nullptr;
		node->next = nullptr;

		if (tail) {
			tail->next = node;
			node->prev = tail;
		}		

		if (!tail) {
			head = node;
		}
		tail = node;
	}

	string DLL::getList() {
		string str = "";
		Node * current = head;
		while (current) {
			str += to_string(current->data) + " -> ";
			current = current->next;
		}
		str += "NULL";
		return str;
	}
}

int main() {
	LinkedList::DLL dll;
	dll.insert(2);
	dll.insert(7);
	dll.insert(10);
	dll.insert(15);

	dll.append(17);
	dll.append(20);
	dll.append(13);
	cout << dll.getList() << endl;
	return 0;
}