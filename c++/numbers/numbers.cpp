#include <iostream>
#include <bitset>

using namespace std;

int main() {

	int input;	
	cout.setf(ios::showbase);

	do {
		cout << "Enter the integer: ";
		cin >> input;

		if (input != -1) {
			cout.setf(ios::hex, ios::basefield);
			cout << "Hex: " << input << endl;

			cout.setf(ios::oct, ios::basefield);
			cout << "Oct: " << input << endl;

			cout.setf(ios::dec, ios::basefield);
			cout << "Dec: " << input << endl;

			bitset<(sizeof(int) * 8)> num(input);
			cout << "Bin: " << num << endl;
		}
	} while (input != -1);
	return 0;
}