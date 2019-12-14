#include <iostream>
#include <string>
#include <cwchar>

using namespace std;

int main() {
	wstring s0;
	wcout << L"Enter name is katakana: ";
	wcin >> s0;

	//s0 = L"どうぞ　" + s0;
	//wcout << s0 << endl;
	wcout << s0 << endl;
	wcout << L"Size of String: " << s0.size() << endl;
	wcout << L"Length of String: " << s0.length() << endl;

	//wstring s1 = L"Fどうぞ　";
	//wcout << L"Size: " << s1.size() << endl;

	for (auto &s: s0) {
		wcout << s << endl;
	}

	//const wchar_t s2[] = L"\x0065\x0301";
	const wchar_t*  s2 = L"😉 = \U0001F609 is ;-)";
	wcout << s2 << endl;
	//fputws(s1, stdout);
	return 0;
}