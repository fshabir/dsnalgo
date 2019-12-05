#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int main() {

	string s0("This is test string");
	char s1[] = "This is test string";

	if (memcmp(s0.data(), s1, s0.length()) == 0) {
		cout << "Strings are same!" << endl;
	} else {
		cout << "Strings are different" << endl;
	}

	string str = "This is tokyo";
	string substr = "is is";
	bool found;

	if (str.find(substr) != string::npos) {
		cout << "Found substring at: " << str.find(substr) << endl;
	}

	string s2("There are two needles in this haystack with needles");
	string s3("needles");

	size_t pos = s2.find(s3);
	if (pos != string::npos) {
		cout << "Found at position: " << pos << endl;	
	}

	pos = s2.find(s3, pos + 1);
	if (pos != string::npos) {
		cout << "Found 2nd needle at: " << pos << endl;
	}

	pos = s2.find("haystack");
	if (pos != string::npos) {
		cout << "haystack is found at: " << pos << endl;
	}

	pos = s2.find_first_not_of("Therearetwoneedlesinthishaystackwithneedles");
	if (pos != string::npos) {
		cout << "First not found at: " << pos << endl;
	}

	//string.find_first_of()
	//string.find_last_not_of()
	//string.find_last_of()

	//string s4("Test");
	string s4;
	s4.reserve(100);
	s4 += "Test";
	s4.resize(2);

	cout << s4 << endl;
	cout << "Size: " << s4.size() << endl;
	cout << "Capacity: " << s4.capacity() << endl;

	//Replace operations
	string s5("This is a really really long string");
	s5.replace(s5.find("really"), string("really").size() + 1, "");
	cout << s5 << endl;

	string s6("This is an example sentence");
	s6.erase(s6.find("example"), string("example").size() + 1);
	cout << s6 << endl;
	return 0;
}