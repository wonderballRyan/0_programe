#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
	queue<int> que1;
	queue<int> que2;//辅助队列，用来备份
	MyStack() {

	}

	void push(int x) {
		que1.push(x);
	}

	int pop() {
		int size = que1.size();
		size--;
		while (size--) {
			que2.push(que1.front());
			que1.pop();
		}

		int result = que1.front();
		que1.pop();
		que1 = que2;
		while (!que2.empty()) {
			que2.pop();
		}
		return result;
	}

	int top() {
		return que1.back();
	}

	bool empty() {
		return que1.empty();
	}
};
int main() {
	MyStack stk;
	stk.push(1);
	stk.push(2);
	cout<<stk.pop()<<endl;
	stk.push(3);
	stk.push(4);
	cout<<stk.pop()<<endl;
	cout<<stk.pop()<<endl;
	cout<<stk.pop()<<endl;
	cout<<stk.empty();
}
