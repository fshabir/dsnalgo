#include <iostream>
#include <string>

using namespace std;

void printMatrix(int **arr, int length, int width) {
	cout << "In function: " << __func__ << " on line number: " << __LINE__ << endl;
	cout << "Matrix: " << endl;
	for (size_t i=0; i<length; i++) {
		for (size_t j=0; j<width; j++) {
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
}

void printMatrix(int arr[][2], int length, int width) {
	cout << "In function: " << __func__ << " on line number: " << __LINE__ << endl;
	cout << "Matrix: " << endl;
	for (size_t i=0; i<length; i++) {
		for (size_t j=0; j<width; j++) {
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}	
}

int main() {
	int **points;
	points = new int*[5];
	for (size_t i=0; i<5; i++) {
		points[i] = new int[3];
	}

	cout << "Enter 5 data points with both 3 values each: ";
	for (size_t i=0; i < 5; i++) {
		for (size_t j=0; j < 3; j++) {
			cin >> points[i][j];
		}
		cout << endl;
	}

	printMatrix(points, 5, 3);

	int _points[3][2];

	cout << endl;
	for (size_t i=0; i<3; i++) {
		for (size_t j=0; j<2; j++) {
			cin >> _points[i][j];
		}
		cout << endl;
	}
	printMatrix(_points, 3, 2);
	return 0;
}