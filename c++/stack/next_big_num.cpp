#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int* nextGreaterElement(int *arr, int size) {
	int * result = new int[size];
	bool found;
	for (int i=0; i<size-1; i++) {
		found = false;
		for (int j=i+1; j<size; j++) {
			if (arr[i] < arr[j]) {
				result[i] = arr[j];
				found = true;
				break;
			}
		}

		if (found == false) {
			result[i] = -1;
		}
	}

	result[size-1] = -1;
	return result;
}

int* nextGreaterElement2(int *arr, int size) {
	int * result = new int[size];
	queue<int> q;
	for (int i=0; i<size-1; i++) {
		if (arr[i] < arr[i+1]) {
			q.push(arr[i+1]);
		}
	}

	int cnt = 0;
	while (!q.empty()) {
		int t = q.front();
		while (arr[cnt] != t) {
			result[cnt++] = t;
		}
		q.pop();
	}

	while (cnt < size) {
		result[cnt++] = -1;
	}
	return result;
}


int main () {

	// 13,3,12,16,15,1
	int * arr = new int[6];
	arr[0] = 13;
	arr[1] = 3;
	arr[2] = 12;
	arr[3] = 16;
	arr[4] = 15;
	arr[5] = 1;

	//arr = nextGreaterElement(arr, 6);
	arr = nextGreaterElement2(arr, 6);

	cout << "[ ";
	for (int i=0; i<6; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
	return 0;
}