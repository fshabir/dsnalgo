#include <iostream>
#include <string>
#include <cstring>
//#include <wstring>

using namespace std;

int main() {

	string s0;
	cout << "Enter your name: ";
	getline(cin, s0);

	cout << "Welcome " << s0 << endl;

	// Input unicode text
	string s1;
	cout << "Enter your name in Katakana: ";
	getline(cin, s1);

	cout << "Welcome " << s1 << " さん" << endl;

	wstring s3;
	cout << "Enter name again: ";
	// cin.getline(name, 7);
	wcin >> s3;
	wcout << "Entered: " << s3 << endl;
	return 0;
}