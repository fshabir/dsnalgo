#include <iostream>
#include <string>

using namespace std;

int main() {
	int numbers1[3] = {4, -5, 1};
	int numbers2[] = {5, 7, 35};

	int numbers3[5];
	int numbers4[5] = {0};

	for (auto num:numbers3) {
		cout << "Number3: " << num << endl;
	}

	for (auto num:numbers4) {
		cout << "Number4: " << num << endl;
	}
	return 0;
}