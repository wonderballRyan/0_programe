#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
public:
	stack<int> stIn;
	stack<int> stOut;

	MyQueue() {

	}
	//添加元素
	void push(int x) {
		stIn.push(x);
	}

	int pop() {
		//只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
		if (stOut.empty()) {
			//从stIn导入数据直到stIn为空
			while (!stIn.empty()) {
				stOut.push(stIn.top());
				stIn.pop();
			}
		}
		int result = stOut.top();
		stOut.pop();
		return result;
	}

	int peek() {
		int res = this->pop();
		stOut.push(res);
		return res;
	}

	bool empty() {
		return stIn.empty() && stOut.empty();
	}
};

int main() {
	MyQueue q;
	q.push(1);
	q.push(2);
	cout<<q.pop()<<endl;
	q.push(3);
	q.push(4);
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.empty();
}
