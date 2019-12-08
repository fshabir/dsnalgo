#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	string s0("This is a really really long string. Just kidding!");

	// Get reference to first character of string
	char &ch = s0.front();

	ch = 't';
	cout << "Changed first char of string using direct reference: " << s0 << endl;
	return 0;
}