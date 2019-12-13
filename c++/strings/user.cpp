#include <iostream>
#include <string>

using namespace std;

int main() {

	string s0;
	cout << "Enter your name: ";
	getline(cin, s0);

	cout << "Welcome " << s0 << endl;
	return 0;
}