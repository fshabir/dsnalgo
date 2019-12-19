#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int * findSum(int arr[], int value, int size) {
  // Sorting function is prepended as sort(arr, low, high)
  int * pair = NULL;
  sort(arr, arr+size);
  unsigned int start = 0;
  unsigned int end = size -1;
  while(start < end) {
    if ((arr[start] + arr[end]) > value) {
      end--;
    } else if ((arr[start] + arr[end]) < value) {
      start++;
    } else {
      pair = new int[2];
      pair[0] = arr[start];
      pair[1] = arr[end];
      break;
    }
  }
	return pair; 
}

int * findSum2(int arr[], int value, int size) {
	//Using hashing in case no duplicates are present in the array
	int * pair = NULL;

	unordered_set<int> nums;
	int diff;
	for(size_t i=0; i<size; i++) {
		if (nums.find(arr[i]) == nums.end()) {
			nums.insert(arr[i]);
		}
	}

	for(size_t i=0; i<size; i++) {
		if (nums.find(value - arr[i]) != nums.end()) {
			pair = new int[2];
			pair[0] = arr[i];
			pair[1] = *(nums.find(value - arr[i]));
			break;
		}
	}

	return pair;
}

int main () {
	int arr[] = {1, 21, 3, 14, 5, 60, 7, 6};
	int * newArr = findSum(arr, 81, 8);
	if (newArr) {
		cout << "First: " << newArr[0] << endl;
      	cout << "Second: " << newArr[1] << endl;
	} else {
		cout << "Not found!!!" << endl;
	}

	newArr = findSum2(arr, 81, 8);
	if (newArr) {
		cout << "First: " << newArr[0] << endl;
      	cout << "Second: " << newArr[1] << endl;
	} else {
		cout << "Not found!!!" << endl;
	}
	return 0;
}