#include <iostream>

using namespace std;

void reArrange(int arr[], int size) {

  int neg = 0, pos = 0;
  for (int i=0; i<size; i++) {
    if (arr[i] < 0) {
      neg++;
    } else {
      pos++;
    }
  }

  int * negative = new int[neg];
  int * positive = new int[pos];
  neg = 0;
  pos = 0;

  for (int i=0; i<size; i++) {
    if (arr[i] < 0) {
      negative[neg++] = arr[i];
    } else {
      positive[pos++] = arr[i];
    }
  }

  int cnt = 0;
  for (int i=0;i<neg; i++) {
    arr[cnt++] = negative[i];
  }

  for (int i=0;i<pos; i++) {
    arr[cnt++] = positive[i];
  }

  delete []negative;
  delete []positive;

}

void print(int arr[], int size) {
	cout << "Array: ";
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main () {
	int arr[] = {-23, 1, -2, 5, 44, -9, 8};

	print(arr, 7);
	reArrange(arr, 7);
	print(arr, 7);
	return 0;
}