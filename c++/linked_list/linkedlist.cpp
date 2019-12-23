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
};

int main() {

	LinkedList list;

	return 0;
}