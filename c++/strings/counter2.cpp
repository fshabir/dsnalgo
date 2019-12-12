#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	string s0 = "This string must be containing multiple letters";
	string needle = "t";
	size_t pos = -1;
	unsigned int count = 0;

	do {
		pos = s0.find("t", pos + 1);
		if (pos != string::npos) {
			count += 1;
		}
	} while (pos != string::npos);
	cout << needle << " found " << count << " times" << endl;
	return 0;
}