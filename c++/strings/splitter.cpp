#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

	char sentence[] = "This is a really sentence with spaces";
	char *word = NULL;

	word = strtok(sentence, " ");
	while (word) {
		cout << word << endl;
		word = strtok(NULL, " ");
	}

	return 0;
}