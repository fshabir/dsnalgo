#include <iostream>

using namespace std;

void rightRotate(int arr[], int size) {
  int temp, prev = arr[0];
  for (int i=1; i<size; i++) {
    temp = arr[i];
    arr[i] = prev;
    prev = temp;
  }
  arr[0] = prev;
}

void rightRotate2(int arr[], int size) {
  int last = arr[size-1];
  for (int i=size-1; i > 0; i--) {
  	arr[i] = arr[i-1];
  }
  arr[0] = last;
}

void print(int arr[], int size) {
	cout << "Array: ";
	for (int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main () {
	int arr[] = {1,2,3,4,5};

	print(arr, 5);
	rightRotate(arr, 5);
	print(arr, 5);

	int arr2[] = {3,6,1,8,4,2};

	print(arr2, 6);
	rightRotate2(arr2, 6);
	print(arr2, 6);
	return 0;	
}