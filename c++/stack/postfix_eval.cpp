#include <iostream>
#include <stack>

using namespace std;

int evaluatePostFix(string exp) {
	stack<int> st;
	int num1, num2;
	char symb;
	for (int i = 0; i < exp.size(); i++) {
		symb = exp[i];
		switch (symb) {
			case '+':
				num2 = st.top();
				st.pop();
				num1 = st.top();
				st.pop();
				st.push(num1 + num2);
				break;
			case '-':
				num2 = st.top();
				st.pop();
				num1 = st.top();
				st.pop();
				st.push(num1 - num2);
				break;
			case '/':
				num2 = st.top();
				st.pop();
				num1 = st.top();
				st.pop();
				st.push(num1 / num2);
				break;
			case '*':
				num2 = st.top();
				st.pop();
				num1 = st.top();
				st.pop();
				st.push(num1 * num2);
				break;
			default:
				st.push(stoi(&symb));
		}
	}
	return st.top();
}

int main() {

	string exp = "921*-8-4+";
	cout << exp << " got evaluted to: " << evaluatePostFix(exp) << endl;

	exp = "642/+";
	cout << exp << " got evaluted to: " << evaluatePostFix(exp) << endl;
	return 0;
}