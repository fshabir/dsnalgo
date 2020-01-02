#pragma once

#include <string>

class Node {
public:
	int data;
	Node * nextElement;
	Node() {
		nextElement = nullptr;
	}
};

class SLL {
private:
	Node * head;
	Node * tail;
public:
	SLL();
	void insert(int);
	void append(int);
	bool deleteNode(int);
	bool findNode(int);
	void insertCycle();
	bool hasLoop();
	int findLength();
	std::string getList();
	void removeDuplicates();
	Node* getHead();
	std::string Union(SLL, SLL);
};