#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	cout << "Another string program" << endl;

	string s0("This is to be sent to file");
	ofstream of("/tmp/test.txt", ios::ate);
	of << s0 << endl;
	of.close();

	cout << "String sent to the file" << endl;

	char s1[256];
	ifstream i_f("/tmp/test.txt", ios::in);
	i_f.getline(s1, 255);

	cout << "Read from file: " << s1 << endl;

	// Check memory contents
	if (memcmp(s1, s0.data(), s0.length()) == 0) {
		cout << "The content of file didn't change after writing" << endl;
	}
	return 0;
}