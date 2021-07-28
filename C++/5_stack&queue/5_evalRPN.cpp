#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				if (tokens[i] == "+") st.push(num2 + num1);
				if (tokens[i] == "-") st.push(num2 - num1);
				if (tokens[i] == "*") st.push(num2 * num1);
				if (tokens[i] == "/") st.push(num2 / num1);
			}
			else {
				st.push(stoi(tokens[i]));//string 转换为int
			}
		}
		int result = st.top();
		st.pop();
		return result;
	}
};
int main() {
	vector<string> tokens = { "4","13","5","/","+" };
	cout << Solution().evalRPN(tokens) << endl;
}
