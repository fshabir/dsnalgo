#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	string s0 = "This is a really long string with lot of Os";
	char needle = 'o';

	unsigned long long count = 0;
	size_t pos = -1;

	do {
		pos = s0.find(needle, pos + 1);
		if (pos != string::npos) {
			count += 1;
		}
	} while (pos != string::npos);

	cout << "Found " << count << " occurrences of " << needle << endl;

	// Finding count using cstring
	const char * s1 = s0.data();
	count = 0;
	while (*s1) {
		if (*s1++ == needle) {
			count += 1;
		}
	}

	cout << "Found " << count << " occurrences of " << needle << endl;

	return 0;
}