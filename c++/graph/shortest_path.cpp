#include <iostream>
#include <list>
#include <limits>

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

	void DFS(int source, int destination, bool * visited, int level, int *found) {
		visited[source] = visited;
		level += 1;

		for (list<int>::iterator it = array[source].begin(); it != array[source].end(); it++) {
			if (*it == destination) {
				if (*found > level) {
					*found = level;
				}
				return;
			} else if (visited[*it] == false) {
				DFS(*it, destination, visited, level, found);
			}
		}
	}

	int shortestPath(int source, int destination) {
		int found = INT_MAX;
		bool * visited = new bool[vertices];
		DFS(source, destination, visited, 0, &found);
		return found == INT_MAX ? -1 : found;
	}
};

int main () {
	Graph g(6);
	
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(3, 5);
	g.addEdge(5, 4);
	g.addEdge(2, 4);
	
	g.printGraph();

	cout << "Shortest Path between 0 and 4 contains edges: " << g.shortestPath(0, 4) << endl;
	return 0;
}