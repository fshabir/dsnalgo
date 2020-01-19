#include <iostream>
#include <list>
#include <stack>

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
		for (int i=0; i<vertices; i++) {
			cout << "[" << i << "] => ";
			for (list<int>::iterator it = array[i].begin(); it != array[i].end(); it++) {
				cout << "|" << *it << "| -> ";
			}
			cout << "NULL" << endl;
		}
	}

	bool isTree() {
		stack<int> st;
		bool * visited = new bool[vertices];
		int edgeCount = 0;
		int current;
		st.push(0);

		while (!st.empty()) {
			current = st.top(); st.pop();
			visited[current] = true;
			for (list<int>::iterator it = array[current].begin(); it != array[current].end(); it++) {
				edgeCount++;
				if (visited[*it] == false) {
					st.push(*it);
				}
			}
		}

		if (edgeCount > (2 * vertices)) return false;
		for (int i=0; i<vertices; i++) {
			if (visited[i] == false) {
				return false;
			}
		}

		return true;
	}
};

int main () {
	Graph g(5);
	
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(3, 4);

	g.printGraph();

	cout << "Is this graph also a tree: " << g.isTree() << endl;
	return 0;
}