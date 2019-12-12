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

	// using strstr()
	const char * s1 = s0.data();
	const char * needle1 = needle.data();
	count = 0;

	do {
		s1 = strstr(s1, needle1);
		if (s1 != NULL) {
			s1++;
			count += 1;
		}
	} while(s1 != NULL);
	cout << needle1 << " found " << count << " times using strstr()" << endl;

	s1 = s0.data();
	count = 0;

	do {
		s1 = strchr(s1, 'i');
		if (s1 != NULL) {
			s1++;
			count += 1;
		}
	} while(s1 != NULL);

	cout << "i found " << count << " times using strchr()" << endl;
	return 0;
}