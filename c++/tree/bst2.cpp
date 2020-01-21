#include <iostream>

using namespace std;

class Node {
public:
	int value;
	Node * leftChild;
	Node * rightChild;

	Node(int val) {
		value = val;
		leftChild = nullptr;
		rightChild = nullptr;
	}
};

class Tree {
private:
	Node * root;
public:
	Tree () {
		root = nullptr;
	}

	void insertBST(int val) {
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
			} else if (current->value <= val) {
				current = current->rightChild;
			}
		}

		if (parent->value > val) {
			parent->leftChild = new Node(val);
		} else if (parent->value <= val) {
			parent->rightChild = new Node(val);
		}
	}

	Node * insertBST(Node * current, int val) {
		if (current == nullptr) {
			current = new Node(val);
			return current;
		}

		if (current->value > val) {
			current->leftChild = insertBST(current->leftChild, val);
		} else {
			current->rightChild = insertBST(current->rightChild, val);
		}
		return current;
	}

	void insertBSTRecursive(int val) {
		root = insertBST(root, val);
	}

	void inorderTraversal(Node * current) {
		if (current != nullptr) {
			inorderTraversal(current->leftChild);
			cout << "|" << current->value << "| -> ";
			inorderTraversal(current->rightChild);
		}
	}

	void printTree() {
		cout << "Printing tree: " << endl;
		inorderTraversal(root);
		cout << endl;
	}
};

int main () {
	Tree bst;
	bst.insertBST(13);
	bst.insertBST(4);
	bst.insertBST(7);
	bst.insertBST(16);
	bst.insertBST(19);
	bst.insertBST(3);
	bst.insertBST(1);
	bst.insertBST(9);
	bst.insertBST(2);

	bst.printTree();

	Tree bst2;
	bst2.insertBSTRecursive(13);
	bst2.insertBSTRecursive(4);
	bst2.insertBSTRecursive(7);
	bst2.insertBSTRecursive(16);
	bst2.insertBSTRecursive(19);
	bst2.insertBSTRecursive(3);
	bst2.insertBSTRecursive(1);
	bst2.insertBSTRecursive(9);
	bst2.insertBSTRecursive(2);

	bst2.printTree();
	return 0;
}