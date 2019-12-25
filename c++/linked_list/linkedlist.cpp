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

	bool search(int value){	
	    Node * current = head;
	    while(current) {
	      if (current->data == value) {
	        return true;
	      }
	      current = current->next;
	    }
	    return false;
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

	bool Delete(int data) {
		Node * prev = nullptr, * current = head;
		if (!head) {
			return false;
		} else if (head->data == data) {
			head = head->next;
			delete current;
			return true;
		} else {
			while(current) {
				if (current->data == data && prev != nullptr) {
					prev->next = current->next;
					delete current;
					return true;
				}
				prev = current;
				current = current->next;
			}
		}
		return false;
	}

	int length(){
	  int count = 0;
	  Node * current = head;
	  while(current) {
	    count += 1;
	    current = current->next;
	  }
	  return count;
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

	list.Delete(2);
	list.print();
	list.Delete(7);
	list.print();
	list.Delete(7);
	list.print();

	cout << "Length of list: " << list.length() << endl;
	return 0;
}