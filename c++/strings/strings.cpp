#include <iostream>
#include <string>

using namespace std;

int main() {

	string s0 = "Test string";
	string s1;
	string s2(s0);
	string s3("Another string");
	char buff[] = "Character buffer";
	string s4(buff);
	string s5(7, 'X');
	string s6(buff, 1, 5);
	string s7(buff, 5);
	string s8(s0.c_str(), 5);

	cout << s0 << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;

	if (s0.compare("Test string") == 0) {
		cout << "Strings are equal" << endl;
	} else {
		cout << "Strings are not equal" << endl;
	}

	return 0;
}