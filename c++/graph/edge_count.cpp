#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
	int vertices;
	list<int> * array;
public:
	Graph(int vertices) {
		this->vertices = vertices;
		array = new list<int>[vertices];
	}

	void addEdge(int source, int destination) {
		array[source].push_front(destination);
		array[destination].push_front(source);
	}

	void printGraph() {
		cout << "Adjacency List: " << endl;
		for (int i=0; i<vertices; i++) {
			cout << "[" << i << "] => ";
			for (list<int>::iterator it = array[i].begin(); it != array[i].end(); it++) {
				cout << "|" << *it << "| -> ";
			}
			cout << "NULL" << endl;
		}
	}

	int uniqueEdges() {
		int sum = 0;
		for (int i = 0; i < vertices; i++)
			for (list<int>::iterator it = array[i].begin(); it != array[i].end(); it++, sum++);
		
		return sum/2;
	}

};

int main() {
	Graph g(9);
	g.addEdge(0,2);
	g.addEdge(0,5);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(5,3);
	g.addEdge(5,6);
	g.addEdge(3,6);
	g.addEdge(6,7);
	g.addEdge(6,8);
	g.addEdge(6,4);
	g.addEdge(7,8);
	g.printGraph();

	cout << "uniqueEdges: " << g.uniqueEdges() << endl;
	return 0;
}