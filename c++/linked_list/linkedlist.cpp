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

	void insert(int data) {
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
	list.insert(3);
	list.insert(5);
	list.insert(7);
	list.print();
	return 0;
}