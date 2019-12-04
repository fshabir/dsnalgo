#include <iostream>
#include <string>

using namespace std;

int main() {
	string s0("This is a really short string");
	string s1("really short");

	size_t pos = s0.find(s1);
	if (pos != string::npos) {
		cout << "Found the substring" << endl;
		cout << "Extracted substring: " << s0.substr(pos, s1.length()) << endl;
	}
	return 0;
}