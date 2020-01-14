#include <iostream>
#include <list>
#include <stack>
#include <string>

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
	}

	void printGraph() {
		cout << "Adjacency list: " << endl;
		for (int i=1; i<vertices; i++) {
			cout << "[" << i << "] => ";
			for (list<int>::iterator it=array[i].begin(); it!=array[i].end(); it++) {
				cout << "|" << *it << "| -> "; 
			}
			cout << "NULL" << endl;
		}
	}

	string dfs(int source) {
		string result = "";
		stack<int> st;
		int current;
		st.push(source);

		while (!st.empty()) {
			current = st.top(); st.pop();
			result += to_string(current);
			for (list<int>::iterator it = array[current].begin(); it != array[current].end(); it++) {
				st.push(*it);
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

	cout << "DFS: " << g.dfs(1) << endl;
	return 0;
}