#include <iostream>

using namespace std;

class Node {
public:
	int value;
	Node * leftChild;
	Node * rightChild;

	Node (int value) {
		this->value = value;
		leftChild = nullptr;
		rightChild = nullptr;
	}

	int getValue() {
		return value;
	}
};

class Tree {
private:
	Node * root;
public:
	Tree () {
		root = nullptr;
	}

	void setRoot(Node * root) {
		this->root = root;
	}

	Node* getRoot() {
		return root;
	}

	Node * insertBST(Node *current, int val) {

		if (current == nullptr) {
			return new Node(val);
		}

		if (current->value > val) {
			current->leftChild = insertBST(current->leftChild, val);
		} else if (current->value <= val) {
			current->rightChild = insertBST(current->rightChild, val);
		}
		return current;
	}

	void insertBST2(int val) {
		if (root == nullptr) {
			root = new Node(val);
			return;
		}

		Node * parent;
		Node * current = root;

		while (current) {
			parent = current;
			if (current->value > val) {
				current = current->leftChild;
			} else {
				current = current->rightChild;
			}
		}

		if (parent->value < val) {
			parent->rightChild = new Node(val);
		} else {
			parent->leftChild = new Node(val);
		}
	}

	void printTree(Node *current) {
		if (current) {
			printTree(current->leftChild);
			cout << "|" << current->value << "| -> ";
			printTree(current->rightChild);
		}
	}
};

int main () {

	Tree t;
	t.insertBST2(13);
	t.insertBST2(4);
	t.insertBST2(7);
	t.insertBST2(16);
	t.insertBST2(19);
	t.insertBST2(3);
	t.insertBST2(1);
	t.insertBST2(9);
	t.insertBST2(2);

	cout << "In-order traversal: "; 
	t.printTree(t.getRoot());
	cout << endl;


	Tree t2;
	t2.setRoot(t2.insertBST(t2.getRoot(), 13));
	t2.setRoot(t2.insertBST(t2.getRoot(), 4));
	t2.setRoot(t2.insertBST(t2.getRoot(), 7));
	t2.setRoot(t2.insertBST(t2.getRoot(), 16));
	t2.setRoot(t2.insertBST(t2.getRoot(), 19));
	t2.setRoot(t2.insertBST(t2.getRoot(), 3));
	t2.setRoot(t2.insertBST(t2.getRoot(), 1));
	t2.setRoot(t2.insertBST(t2.getRoot(), 9));
	t2.setRoot(t2.insertBST(t2.getRoot(), 2));

	cout << "In-order traversal: "; 
	t2.printTree(t2.getRoot());
	cout << endl;
	return 0;
}