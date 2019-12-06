#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	cout << "Another string program" << endl;

	string s0("This is to be sent to file");
	ofstream of("/tmp/test.txt", ios::ate);
	of << s0 << endl;
	of.close();

	cout << "String sent to the file" << endl;

	return 0;
}