#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

	string s0 = "This is another really long string used for iteration";
	string::iterator it = s0.begin();

	while (it != s0.end()) {
		cout << "Character: " << *(it++) << endl;
	}

	const char * pCh = s0.c_str();
	while (pCh && *pCh) {
		cout << *pCh++;
	}
	cout << endl;
	return 0;
}