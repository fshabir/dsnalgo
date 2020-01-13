#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string exp) {
	char c;
	stack<char> st;
	for (int i=0; i<exp.size(); i++) {
		c = exp[i];
		switch (c) {
			case '{':
			case '(':
			case '[':
				st.push(c);
				break;
			case '}':
				if (st.top() != '{') {
					return false;
				}
				st.pop();
				break;
			case ')':
				if (st.top() != '(') {
					return false;
				}
				st.pop();
				break;
			case ']':
				if (st.top() != '[') {
					return false;
				}
				st.pop();
				break;
		}
	}

	return st.empty() ? true : false;
}

int main() {
	string exp = "{[({})]}";
	cout << "Is balanced: " << isBalanced(exp) << endl;
	return 0;
}