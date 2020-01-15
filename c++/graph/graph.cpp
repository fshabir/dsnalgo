//#pragma once
#include <list>
#include <iostream>

using namespace std;

class Graph {
private:
	int vertices;
	list<int> * array;
public:
	Graph (int vertices) {
		this->vertices = vertices;
		array = new list<int>[vertices];
	}

	void addEdge(int source, int destination) {
		array[source].push_back(destination);
	}

	void printGraph() {
		cout << "Adjacency list of directed graph: " << endl;
		for (int i=0; i<vertices; i++) {
			cout << "| " << i << " | => ";
			for(list<int>::iterator it = array[i].begin(); it != array[i].end(); it++) {
				cout << "[" << *it << "]" << " -> ";
			}
			cout << "NULL" << endl;
		}
	}
};


int main() {
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	cout << endl;
	g.printGraph();
	return 0;
}
