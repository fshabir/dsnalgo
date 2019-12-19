#include <iostream>

using namespace std;

int * findProduct(int arr[], int size)  { 
    int * product = new int[size]; 
    long long total = 1;
    for (int i=0; i<size; i++) {
      total *= arr[i];
    }

    for (int i=0; i<size; i++) {
      product[i] = total / arr[i];
    }
    return product; 
}

void print(int arr[], size_t size) {
	cout << "Array: ";
	for (size_t i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {2,-4,3,-6,1,5};

	print(arr, 6);
	int *newArr = findProduct(arr, 6);
	print(newArr, 6);
	return 0;
}