#include <iostream>

using namespace std;

int * mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size)
{
    int * arr3; // creating new array
    arr3 = new int[arr1Size + arr2Size];
    size_t cnt1 = 0, cnt2 = 0, cnt3=0;

    while(cnt1 < arr1Size && cnt2 < arr2Size) {
        if (arr1[cnt1] < arr2[cnt2]) {
            arr3[cnt3++] = arr1[cnt1++];
        } else {
            arr3[cnt3++] = arr2[cnt2++];
        }
    }

    if (cnt1 < arr1Size) {
        while (cnt1 < arr1Size) {
            arr3[cnt3++] = arr1[cnt1++];
        }
    } else if (cnt2 < arr2Size) {
        while (cnt2 < arr2Size) {
            arr3[cnt3++] = arr2[cnt2++];
        }
    }
    return arr3; // returning array
}

void print(int arr[], size_t size) {
	cout << "Array: ";
	for (size_t i=0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr1[] = {1,3,4,5};
	int arr2[] = {-3,0,1,4};
	int *mergedArray;

	print(arr1, 4);
	print(arr2, 4);
	mergedArray = mergeArrays(arr1, arr2, 4, 4);
	print(mergedArray, 8);

	return 0;
}