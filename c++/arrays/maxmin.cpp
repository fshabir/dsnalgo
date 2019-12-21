#include <iostream>

using namespace std;

void maxMin(int arr[], int size) {
  int * temp = new int[size];
  int front = 0;
  int back = size-1;
  int cnt = 0;

  while(front < back) {
    temp[cnt++] = arr[back--];
    temp[cnt++] = arr[front++];
  }

  for (int i=0; i < size; i++) {
    arr[i] = temp[i];
  }
  delete [] temp;
}

void print(int arr[], int size) {
  cout << "Array: ";
  for (int i=0; i<size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {

  int arr[] = {12,23,34,45,56,67,78};

  print(arr, size);
  maxMin(arr, size);
  print(arr, size);
  return 0;
}