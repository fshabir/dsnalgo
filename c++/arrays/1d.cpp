#include <iostream>
#include <string>

using namespace std;

int main() {
	unsigned long long guesses[10];

	unsigned int cnt = 0;
	do {
		cout << "Enter a guess: " << endl;
		cin >> guesses[cnt];
	} while(cnt++ < 10);

	unsigned long sum = 0;
	for (auto num:guesses) {
		sum += num;
	}

	cout << "Sum of guesses is: " << sum << endl;
	return 0;
}