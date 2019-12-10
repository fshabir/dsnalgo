#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdio.h>

using namespace std;

int main() {

	char sentence[] = "This is a really sentence with spaces";
	char *word = NULL;

	word = strtok(sentence, " ");
	while (word) {
		cout << word << endl;
		word = strtok(NULL, " ");
	}

	// Splitting using string stream
	stringstream ss(string("This is a really sentence with spaces"));
	string part;

	cout << "Splitting using std:stringstream" << endl;
	while (getline(ss, part, ' ')) {
		cout << part << endl;
	}

	return 0;
}