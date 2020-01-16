#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
private:
	int vertices;
	list<int>* array;
public:
	Graph(int vertices) {
		this->vertices = vertices;
		array = new list<int>[vertices];
	}

	void addEdge(int source, int destination) {
		array[source].push_front(destination);
	}

	void printGraph() {
		cout << "Adjacency list: " << endl;
		for (int i=0; i<vertices; i++) {
			cout << "[" << i << "] => ";
			for (list<int>::iterator it = array[i].begin(); it != array[i].end(); it++) {
				cout << "|" << *it << "| -> ";
			}
			cout << "NULL" << endl;
		}
	}

	int getVertices() {
		return vertices;
	}

	void DFS(Graph g, bool *visited, int source) {
		visited[source] = true;
		cerr << source << " => ";

		for (list<int>::iterator it = array[source].begin(); it != array[source].end(); it++) {
			if (visited[*it] == false) {
				DFS(g, visited, *it);
			}
		}
	}

	int findMotherVertex(Graph g) {
		bool *visited = new bool[g.getVertices()];
		
		int lastV;

		for (int i=0; i < g.getVertices(); i++) {
			if (visited[i] == false) {
				DFS(g, visited, i);
				lastV = i;
			}
		}
		cerr << endl << "Last Vertex: " << lastV << endl;

		for (int i=0; i<g.getVertices(); i++) {
			visited[i] = false;
		}

		DFS(g, visited, lastV);
		cout << endl;

		bool nonVisited = false;
		for (int i=0; i<g.getVertices(); i++) {
			if (visited[i] == false) {
				nonVisited = true;
				break;
			}
		}

		return nonVisited ? -1 : lastV;
	}
};

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(3, 0);
	g.addEdge(3, 1);
	g.printGraph();

	int mother = g.findMotherVertex(g);

	cout << "Mother vertex for this graph is: " << mother << endl;
	return 0;
}