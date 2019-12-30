#pragma once

#include <string>

class SLL {
private:
	struct Node {
		int data;
		Node * nextElement;
	};
	Node * head;
	Node * tail;
public:
	SLL();
	void insert(int);
	void append(int);
	bool deleteNode(int);
	int findNode(int);
	void insertCycle();
	bool hasLoop();
	int findLength();
	std::string getList();
};