#include <iostream>
#include "sll.h"

using namespace std;

SLL::SLL() {
	this->head = nullptr;
	this->tail = nullptr;
}

void SLL::insert(int data) {
	Node * newNode = new Node();
	newNode->data = data;
	newNode->nextElement = head;
	head = newNode;

	if (tail == nullptr) {
		tail = newNode;
	}
}

void SLL::append(int data) {
	Node * newNode = new Node();
	newNode->data = data;
	if (tail == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		tail->nextElement = newNode;
		tail = newNode;
	}
}

bool SLL::deleteNode(int data) {
	if (head == nullptr) return false;
	if (head->data == data) {
		head = head->nextElement;
		return true;
	}

	Node * previous = head, * current = head->nextElement, * temp;
	while (current) {
		if (current->data == data) {
			previous->nextElement = current->nextElement;
			temp = current;
			if (current == tail) {
				tail = previous;
			}
			delete temp;
			return true;
		}
		previous = current;
		current = current->nextElement;
	}
	return false;
}

bool SLL::findNode(int data) {
	Node * current = head;
	while (current) {
		if (current->data == data) {
			return true;
		}
		current = current->nextElement;
	}
	return false;
}

void SLL::insertCycle() {
	if (head != nullptr) {
		tail->nextElement = head;
	}
}

bool SLL::hasLoop() {
	if (head == nullptr || head == tail) return false;
	Node * slow = head, * fast = head->nextElement;
	while (fast != nullptr) {
		if (slow == fast) {
			return true;
		}
		slow = slow->nextElement;
		fast = fast->nextElement;
		if (fast) {
			fast = fast->nextElement;
		}
	}
	return false;
}

int SLL::findLength() {
	int length = 0;
	Node * current = head;
	while (current != nullptr && current != tail) {
		length += 1;
		current = current->nextElement;
	}

	if (current == tail) {
		length += 1;
	}
	return length;
}

string SLL::getList() {
	int length = this->findLength() + 1;
	Node * current = head;
	string list = "";
	while (current != nullptr && length > 0) {
		list += to_string(current->data) + " -> ";
		current = current->nextElement;
		length -= 1;
	}
	list += "NULL";
	return list;
}

void SLL::removeDuplicates() {
	if (head == nullptr || head == tail) return;
	Node * current = head, * previous = head, * next = head->nextElement, * temp;
	while (current != nullptr) {
		while(next != nullptr) {
			if (current->data == next->data) {
				temp = next;
				previous->nextElement = next->nextElement;
				next = next->nextElement;
				delete temp;
			} else {
				previous = next;
				next = next->nextElement;
			}
		}
		current = current->nextElement;
		previous = current;
		if (previous) {
			next = previous->nextElement;
		}
	}
}

Node* SLL::getHead() {
	return this->head;
}

string SLL::Union(SLL list1, SLL list2) {
	SLL list3;
	Node * current;
	current = list1.getHead();
	while (current != nullptr) {
		list3.append(current->data);
		current = current->nextElement;
	}

	current = list2.getHead();
	while (current != nullptr) {
		list3.append(current->data);
		current = current->nextElement;
	}

	list3.removeDuplicates();
	return list3.getList();
}

int SLL::findNth(int n) {
	Node * current = this->head;
	int remaining, total = 0;
	while (current != nullptr) {
		total += 1;
		current = current->nextElement;
	}

	current = this->head;
	remaining = total;
	while (current != nullptr) {
		if (remaining == n) {
			return current->data;
		}
		remaining -= 1;
		current = current->nextElement;
	}

	return -1;
}

std::string SLL::Intersection(SLL list1, SLL list2) {
	SLL list3;
	Node * current, * next;
	current = list1.getHead();
	while (current != nullptr) {
		next = list2.getHead();
		while (next != nullptr) {
			if (current->data == next->data) {
				list3.append(current->data);
				break;
			}
			next = next->nextElement;
		}
		current = current->nextElement;
	}
	list3.removeDuplicates();
	return list3.getList();
}

int main() {
	SLL list;
	cout << "List at the start: " << list.getList() << endl;

	list.insert(5);
	list.insert(8);
	cout << "List after inserting 5 and 8: " << list.getList() << endl;

	list.append(3);
	list.append(1);
	cout << "List after appending 3 and 1: " << list.getList() << endl;

	list.deleteNode(5);
	cout << "List after deleting 5: " << list.getList() << endl;

	list.deleteNode(1);
	cout << "List after deleting 1: " << list.getList() << endl;

	cout << "Does list have loop: " << list.hasLoop() << endl;

	cout << "Is 8 present in the list: " << list.findNode(8) << endl;
	cout << "Is 1 present in the list: " << list.findNode(1) << endl;

	cout << "Length of list: " << list.findLength() << endl;
	list.append(9);
	list.append(13);
	cout << "List after appending 9 and 13: " << list.getList() << endl;

	list.insertCycle();
	cout << "List after inserting loop: " << list.getList() << endl;

	cout << "Does list have loop: " << list.hasLoop() << endl;

	SLL list2;
	list2.append(2);
	list2.append(4);
	list2.append(6);
	list2.append(8);
	list2.append(4);
	list2.append(6);
	list2.append(6);
	list2.append(10);
	list2.append(8);
	list2.append(12);
	cout << "List2 initially: " << list2.getList() << endl;
	list2.removeDuplicates();
	cout << "List2 after removing duplicates: " << list2.getList() << endl;

	SLL list3, list4;
	list3.append(8);
	list3.append(9);
	list3.append(6);
	list3.append(4);

	list4.append(6);
	list4.append(2);
	list4.append(6);
	list4.append(7);
	list4.append(7);
	cout << "List 3: " << list3.getList() << endl;
	cout << "List 4: " << list4.getList() << endl;
	cout << "Union of list 3 and list 4: " << list3.Union(list3, list4) << endl;

	SLL list5, list6;
	list5.append(1);
	list5.append(3);
	list5.append(6);
	list5.append(1);

	list6.append(2);
	list6.append(3);
	list6.append(1);
	list6.append(6);
	list6.append(3);
	cout << "List 5: " << list5.getList() << endl;
	cout << "List 6: " << list6.getList() << endl;
	cout << "Intersection of List 5 and List 6: " << list5.Intersection(list5, list6) << endl;

	cout << "2nd element from the last of List 6 is: " << list6.findNth(2) << endl;
	cout << "4th element from the last of List 6 is: " << list6.findNth(4) << endl;
	cout << "10th element from the last of List 6 is: " << list6.findNth(10) << endl;
	return 0;
}