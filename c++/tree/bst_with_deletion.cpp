#include <iostream>

using namespace std;

class Node {
public:
	int value;
	Node * leftChild;
	Node * rightChild;

	Node () {
		value = 0;
		leftChild = nullptr;
		rightChild = nullptr;
	}

	Node (int val) {
		value = val;
		leftChild = nullptr;
		rightChild = nullptr;
	}
};

class BST {
private:
	Node * root;
public:
	BST () {
		root = nullptr;
	}

	BST (int val) {
		root = new Node(val);
	}

	void insertBST(int val) {
		if (root == nullptr) {
			root = new Node(val);
			return;
		}

		Node * current = root;
		Node * parent;

		while (current != nullptr) {
			parent = current;
			if (current->value > val) {
				current = current->leftChild;
			} else {
				current = current->rightChild;
			}
		}

		if (parent->value > val) {
			parent->leftChild = new Node(val);
		} else {
			parent->rightChild = new Node(val);
		}
	}

	// bool deleteBST(Node * current, int val) {
	// 	/**
	// 	 * Must handle these cases
	// 	 * 1) Case when root is null
	// 	 * 2) Case when the node has no children (leaf node)
	// 	 * 3) Case when the node has 1 child node
	// 	 * 4) Case when the node has 2 children
	// 	**/

	// 	// Case 1
	// 	if (root == nullptr) {
	// 		return false;
	// 	}

	// 	// Find the node to be deleted
	// 	//Node * current = node;
	// 	Node * parent = nullptr;

	// 	while (current != nullptr) {
	// 		parent = current;
	// 		if (current->value == val) {
	// 			break;
	// 		} else if (current->value > val) {
	// 			current = current->leftChild;
	// 		} else {
	// 			current = current->rightChild;
	// 		}
	// 	}

		
	// 	if (current == nullptr) return false; // matching node not found

	// 	// Case 2
	// 	if (current->leftChild == nullptr && current->rightChild == nullptr) {
	// 		if (current == root) {
	// 			delete root;
	// 			root = nullptr;
	// 			return true;
	// 		} else if (parent->value > val) {
	// 			delete parent->leftChild;
	// 			parent->leftChild = nullptr;
	// 			return true;
	// 		} else {
	// 			delete parent->rightChild;
	// 			parent->rightChild = nullptr;
	// 			return true;
	// 		}
	// 	} else if (current->rightChild == nullptr) {
	// 		// Case 3 - Left child only
	// 		if (current == root) {
	// 			delete root;
	// 			root = current->leftChild;
	// 			return true;
	// 		} else if (parent->value > val) {
	// 			delete parent->leftChild;
	// 			parent->leftChild = current->leftChild;
	// 			return true;
	// 		} else {
	// 			delete parent->rightChild;
	// 			parent->rightChild = current->rightChild;
	// 			return true;
	// 		}
	// 	} else if (current->leftChild == nullptr) {
	// 		// Case 4 - Right child only
	// 		if (current == root) {
	// 			delete root;
	// 			root = current->rightChild;
	// 			return true;
	// 		} else if (parent->value > val) {
	// 			delete parent->leftChild;
	// 			parent->leftChild = current->rightChild;
	// 			return true;
	// 		} else {
	// 			delete parent->rightChild;
	// 			parent->rightChild = current->rightChild;
	// 			return true;
	// 		}
	// 		delete current;
	// 	} else if (current->leftChild != nullptr && current->rightChild != nullptr) {
	// 		// Case 5 - Both Left and Right child
	// 		Node * descendant = current->rightChild;
			
	// 		// Descend to the Left most child of right subtree
	// 		while (descendant->leftChild != nullptr) {
	// 			descendant = descendant->leftChild;
	// 		}

	// 		int temp = descendant->value;
	// 		deleteBST(root, descendant->value);
	// 		current->value = temp;
	// 		return false;
	// 	}
	// }

	Node * getRoot() {
		return root;
	}

    bool Delete(Node* currentNode, int value) {

	    if(root==NULL){
	        return false;
	    }
	    
	    Node* parent; //To Store parent of currentNode
	    while(currentNode!=NULL && (currentNode->value != value)) {
	        parent=currentNode;
	        if (currentNode->value > value)
	            currentNode=currentNode->leftChild;
	        else
	            currentNode=currentNode->rightChild;

	    }

	    if(currentNode==NULL)
	        return false;
	    else if(currentNode->leftChild == NULL && currentNode->rightChild == NULL) {
	        //1. Node is Leaf Node
	        //if that leaf node is the root (a tree with just root)
	        if(root->value==currentNode->value){
	            delete root;
	            root=NULL;
	            return true;
	        }
	        else if(currentNode->value < parent->value){
	            delete parent->leftChild;
	            parent->leftChild=NULL;
	            return true;
	        }
	        else{
	            delete parent->rightChild;
	            parent->rightChild=NULL;
	            return true;
	        }

	    } else if(currentNode->rightChild == NULL) {
	         
	        if(root->value==currentNode->value){
	            delete root;
	            root=currentNode->leftChild;
	            return true;
	        }
	        else if(currentNode->value<parent->value){
	            delete parent->leftChild;
	            parent->leftChild=currentNode->leftChild;
	            return true;
	        }
	        else{
	            delete parent->rightChild;
	            parent->rightChild=currentNode->leftChild;
	            return true;
	        }

	    }
	    else if(currentNode->leftChild == NULL) {
	        if(root->value==currentNode->value){
	            delete root;
	            root=currentNode->rightChild;
	            return true;
	        }
	        else if(currentNode->value<parent->value){
	            delete parent->leftChild;
	            parent->leftChild=currentNode->rightChild;
	            return true;
	        }
	        else{
	            delete parent->rightChild;
	            parent->rightChild=currentNode->rightChild;
	            return true;
	        }

	    }
	    else {
	        //Find Least Value Node in right-subtree of current Node
	        Node* leastNode = findLeastNode(currentNode->rightChild);
	        //Set CurrentNode's Data to the least value in its right-subtree
	        int tmp=leastNode->value;
	        Delete(root,tmp);
	        currentNode->value=leastNode->value;
	        //Delete the leafNode which had the least value


	        return true;
	    }


	}

	//Helper function to find least value node in right-subtree of currentNode
	Node* findLeastNode(Node* currentNode) {

	    Node* temp = currentNode;

	    while (temp->leftChild != NULL) {
	        temp = temp->leftChild;
	    }

	    return temp;

	}

	void inorderTraversal(Node * current) {
		if (current != nullptr) {
			inorderTraversal(current->leftChild);
			cout << "|" << current->value << "| -> ";
			inorderTraversal(current->rightChild);
		}
	}

	void printBST() {
		cout << "Printing tree: " << endl;
		inorderTraversal(root);
		cout << endl;
	}
};


int main () {
	BST bst(13);
	bst.insertBST(4);
    bst.insertBST(7);
    bst.insertBST(16);
    bst.insertBST(19);
    bst.insertBST(3);
    bst.insertBST(1);
    bst.insertBST(9);
    bst.insertBST(2);
    bst.insertBST(5);
    bst.insertBST(15);

    bst.printBST();

    bst.Delete(bst.getRoot(), 4);
    //bst.deleteBST(bst.getRoot(), 4);
    bst.printBST();
	return 0;
}