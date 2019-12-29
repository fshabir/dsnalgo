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

	void DLL::reverse() {
		Node * prev, * curr, * next;
		if (head) {
			curr = head;
			prev = head->prev;
			next = head->next;
		} else {
			return; // List if empty
		}

		while (next) {
			curr->next = prev;
			curr->prev = next;

			prev = curr;
			curr = next;
			next = next->next;
		}
		curr->prev = nullptr;
		curr->next = prev;
		tail = head;
		head = curr;
	}

	void DLL::reverse2() {
		Node *temp, * current = head;
		while (current) {
			temp = current->next;
			current->next = current->prev;
			current->prev = temp;
			current = temp;
		}
		temp = head;
		head = tail;
		tail = temp;
	}

	void DLL::insertLoop() {
		Node * node = head;
		if (node == nullptr) return;
		
		while(node->next) {
			node = node->next;
		}
		node->next = head;
	}

	bool DLL::detectLoop() {
		Node * slow = head;
		Node * fast = head;
		if (fast != nullptr) {
			fast = fast->next;
		}

		while (fast != nullptr) {
			if (fast == slow) {
				return true;
			}
			slow = slow->next;
			fast = fast->next;
			if (fast != nullptr) {
				fast = fast->next;
			}
		}
		return false;
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
	dll.reverse();
	cout << dll.getList() << endl;
	dll.reverse2();
	cout << dll.getList() << endl;
	cout << "Dectected Loop: " << dll.detectLoop() << endl;
	dll.insertLoop();
	//cout << dll.getList() << endl;
	cout << "Dectected Loop: " << dll.detectLoop() << endl;
	return 0;
}