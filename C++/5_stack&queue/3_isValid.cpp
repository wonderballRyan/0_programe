#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<int> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') st.push(')');
			else if (s[i] == '{') st.push('}');
			else if (s[i] == '[') st.push(']');
			//第三种情况，遍历字符串匹配的过程中，栈已经空了，说明右括号没有找到对应的左括号
			//第二种情况，发现栈里没有我们要匹配的字符
			else if (st.empty() || st.top() != s[i]) return false;
			else st.pop();//st.top()等于s[i]相等，则栈弹出元素
		}

		//第一种情况，遍历完字符串，栈不为空，说明有相应的左括号没有匹配的右括号
		return st.empty();
	}
};
int main() {
	string str = "([{}])";
	Solution s;
	cout << s.isValid(str) << endl;
}
