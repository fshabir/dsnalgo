#include "queue.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
using namespace DS;


string* findBin(int n) {
	Queue * q = new Queue(n + 1);
	q->enqueue(1);

	string * result = new string[n];
	for (int i=0; i<n; i++) {
		result[i] = to_string(q->dequeue());
		q->enqueue(stoi(result[i] + "0"));
		q->enqueue(stoi(result[i] + "1"));
	}
	return result;
}


int main() {
	string * result = nullptr;
	result = findBin(3);
	cout << "[ ";
	for (int i=0; i<3; i++) {
		cout << result[i] << " ";
	}
	cout << "]" << endl;

	result = findBin(5);
	cout << "[ ";
	for (int i=0; i<5; i++) {
		cout << result[i] << " ";
	}
	cout << "]" << endl;

	result = findBin(100);
	cout << "[ ";
	for (int i=0; i<100; i++) {
		cout << result[i] << " ";
	}
	cout << "]" << endl;
	return 0;
}