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

	bool checkPath(int source, int destination) {
		stack<int> st;
		bool * visited = new bool[vertices];
		st.push(source);
		int current;

		while (!st.empty()) {
			current = st.top(); st.pop();
			visited[current] = true;
			for (list<int>::iterator it = array[current].begin(); it != array[current].end(); it++) {
				if (visited[*it] != true) {
					st.push(*it);
				}
			}
		}

		return visited[destination];
	}
};

int main () {
	Graph g(9);
	
	g.addEdge(0, 2);
	g.addEdge(0, 5);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(5, 3);
	g.addEdge(5, 6);
	g.addEdge(3, 6);
	g.addEdge(6, 7);
	g.addEdge(6, 8);
	g.addEdge(6, 4);
	g.addEdge(7, 8);

	g.printGraph();

	cout << "Does path exist between 0 and 7: " << g.checkPath(0, 7) << endl;
	return 0;
}