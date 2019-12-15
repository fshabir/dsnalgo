#include <iostream>
#include <string>

using namespace std;

double average(unsigned long long *arr, size_t size) {
	if (size == 0) return size;

	double sum = 0;
	for (size_t i=0; i<size; i++){
		sum += arr[i];
	}

	return sum / size;
}

void print(unsigned long long arr[], size_t size) {
	for(size_t i=0; i < size; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void doublify(unsigned long long arr[], size_t size) {
	for(size_t i=0; i<size; i++) {
		arr[i] = arr[i] * 2;
	}
}

int main() {
	unsigned long long numbers[10];

	cout << "Enter a 10 positive numbers: " << endl;
	for (size_t i=0; i<10; i++){
		cin >> numbers[i];
	}

	unsigned long sum = 0;
	for (auto num:numbers) {
		sum += num;
	}

	cout << "Input array: ";
	print(numbers, 10);

	cout << "Sum of numbers is: " << sum << endl;

	cout << "Average of array is: " << average(numbers, sizeof(numbers)/sizeof(unsigned long long)) << endl;

	cout << "Size of array is: " << sizeof(numbers) / sizeof(unsigned long long) << endl;

	doublify(numbers, 10);
	cout << "Doubled array: ";
	print(numbers, 10);
	return 0;
}