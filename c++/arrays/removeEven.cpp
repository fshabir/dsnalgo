#include <iostream>

using namespace std;

int removeEven( int *& Arr, int size ) {
  int m = 0;
  // Write your code here
  size_t oddCount = 0;
  for (size_t i=0; i < size; i++) {
    if (Arr[i] % 2 != 0) {
      oddCount += 1;
    }
  }

  int * odds = new int[oddCount];
  size_t counter = 0;
  for (size_t i=0; i < size; i++) {
    if (Arr[i] % 2 != 0) {
      odds[counter++] = Arr[i];
    }
  }
  delete [] Arr;
  Arr = odds;
  return oddCount;
}

void print(int array[], size_t size) {
	cout << "Array: ";
	for(size_t i=0; i<size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {

	int *case1 = new int[7]{-23, 1, -2, 5, 44, -9, 8};
	int *case2 = new int[7]{14, -3, 56, 29, -39, -94, 87};

	print(case1, 7);
	size_t one = removeEven(case1, 7);
	print(case1, one);

	print(case2, 7);
	size_t two = removeEven(case2, 7);
	print(case2, two);
	return 0;
}