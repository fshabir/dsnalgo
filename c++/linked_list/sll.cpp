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

	Node * previous = head, * current = head->nextElement;
	while (current) {
		if (current->data == data) {
			previous->nextElement = current->nextElement;
			return true;
		}
		previous = current;
		current = current->nextElement;
	}
	return false;
}

int SLL::findNode(int) {
	return 0;
}

void SLL::insertCycle() {

}

bool SLL::hasLoop() {

	return false;
}

int SLL::findLength() {
	return 0;
}

string SLL::getList() {
	Node * current = head;
	string list = "";
	while (current) {
		list += to_string(current->data) + " -> ";
		current = current->nextElement;
	}
	list += "NULL";
	return list;
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
	return 0;
}