#include <iostream>
#include <map>

using namespace std;

int findFirstUnique(int arr[], int size) {
    // Write your code here
    map<int, int> m;
    for (int i=0; i<size; i++) {
        m[arr[i]]++;
    }

    for (int i=0; i<size; i++) {
        if(m[arr[i]] == 1) {
            return arr[i];
        }
    }

    return - 1;
}


int main() {

	int arr[] = {2, 3, 9, 2, 3, 6};

	int ans = findFirstUnique(arr, 6);

	cout << "First unique: " << ans << endl;
	return 0;
}