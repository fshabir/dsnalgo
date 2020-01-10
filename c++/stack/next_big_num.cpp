#include <iostream>
#include <stack>

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


int main () {

	int * arr = new int[6];
	arr[0] = 4;
	arr[1] = 6;
	arr[2] = 3;
	arr[3] = 2;
	arr[4] = 8;
	arr[5] = 1;

	arr = nextGreaterElement(arr, 6);

	cout << "[ ";
	for (int i=0; i<6; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
	return 0;
}