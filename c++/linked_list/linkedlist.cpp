#include <iostream>

using namespace std;

class LinkedList {
private:
	struct Node {
		int data;
		Node * next;
	};
	Node * head;
public:
	LinkedList() {
		head = nullptr;
	}

	void insertAtTail(int value) {
	    Node * newNode = new Node();
	    newNode->data = value;
	    newNode->next = nullptr;

	    if (head == nullptr) {
	      head = newNode;
	    } else {
	      while (head->next != nullptr) {
	        head = head->next;
	      }
	      head->next = newNode;
	    }
	 }  

	void insert(int data) {
		Node * node = new Node;
		node->data = data;
		node->next = head;
		head = node;
	}

	void append(int data) {
		Node * node = new Node;
		node->data = data;
		node->next = nullptr;

		if (!head) {
			head = node;
		} else {
			Node * start = head;
			while(start->next) {
				start = start->next;
			}
			start->next = node;
		}
	}

	void print() {
		cout << "LinkedList: ";
		Node * start = head;
		while(start) {
			cout << start->data << " ";
			start = start->next;
		}
		cout << endl;
	}

};

int main() {
	LinkedList list;
	list.insert(2);
	list.append(3);
	list.append(5);
	list.append(7);

	list.insert(9);
	list.insert(7);
	list.print();
	return 0;
}