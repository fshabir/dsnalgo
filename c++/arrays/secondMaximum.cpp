#include <iostream>

using namespace std;

int findSecondMaximum(int arr[], int size) {
    int temp;
    for (int i=0; i<2; i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    return arr[1];
}

int main () {

	int arr[] = {-2,4,18,37,-6,28};

	int ans = findSecondMaximum(arr, 6);

	cout << "Second maximum is: " << ans << endl;
	return 0;
}