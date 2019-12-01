#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	char sentence[] = "This is a pretty long sentence that needs to be saved in a text file";
	// ofstream of("/tmp/test.txt", ofstream::out);
	ofstream of("/tmp/test.txt", ios_base::out);
	of << sentence << endl;
	of.close();
	return 0;
}