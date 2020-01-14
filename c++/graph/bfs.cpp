#include <iostream>
#include <queue>
#include <list>
#include <string>

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
	}

	void printGraph() {
		cout << "Adjacency List: " << endl;
		for (int i=1; i<vertices; i++) {
			cout << "[" << i << "] => ";
			for (list<int>::iterator it = array[i].begin(); it != array[i].end(); it++) {
				cout << "|" << (*it) << "| -> ";
			}
			cout << "NULL" << endl;
		}
	}

	list<int>* getArray() {
		return array;
	}

	string bfs(Graph g, int source) {
		string result = "";

		queue<int> q;
		q.push(source);
		int current;
		list<int> * vertices = g.getArray();
		while (!q.empty()) {
			current = q.front();
			q.pop();
			result += to_string(current);
			for (list<int>::iterator it = vertices[current].begin(); it != vertices[current].end(); it++) {
				q.push(*it);
			}
			
		}
		return result;
	}
};

int main() {
	Graph g(6);
	g.addEdge(1,3);
	g.addEdge(1,2);
	g.addEdge(2,5);
	g.addEdge(2,4);

	g.printGraph();
	cout << "BFS: " << g.bfs(g, 1) << endl;
	return 0;
}