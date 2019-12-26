#include "dll.h"
#include <iostream>

using namespace std;

namespace LinkedList {
	DLL::DLL() {
		head = nullptr;
		tail = nullptr;
	}

	void DLL::insert(int data) {
		Node * node;
		node->next = head;
		node->prev = nullptr;
		node->data = data;

		if (head) {
			head->prev = node;
		}
		head = node;

	}

	void DLL::append(int data) {
		Node * node;
		node->data = data;
		node->prev = tail;
		node->next = nullptr;

		if (tail) {
			tail->next = node;
		}
		tail = node;
	}
}

int main() {
	LinkedList::DLL dll;
	return 0;
}