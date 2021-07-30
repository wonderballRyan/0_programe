#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	//小顶堆
	//pair是将2个数据组合成一个数据，当需要这样的需求时就可以使用pair，如stl中的map就是将key和value放在一起来保存。
	//另一个应用是，当一个函数需要返回2个数据的时候，可以选择pair。 
	//pair的实现是一个结构体，主要的两个成员变量是first second。
	//因为是使用struct不是class，所以可以直接使用pair的成员变量。
	class mycomparison {
	public:
		bool operator()(const pair<int,int>& lhs,const pair<int,int> & rhs) {
			return lhs.second > rhs.second;
		}
	};
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//要统计元素出现频率
		unordered_map<int, int> map;//map<nums[i]，对应出现的次数>
		for (int i = 0; i < nums.size(); i++) {
			map[nums[i]]++;
		}

		//对频率排序
		//定义一个小顶堆，大小为k
		//定义：priority_queue<Type, Container, Functional>
		//Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector, deque等等，但不能用 list。STL里面默认用的是vector)，Functional 就是比较的方式。
		priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

		//用固定大小为k的小顶堆，扫面所有频率的数值
		//迭代器是一种检查容器内元素并遍历元素的数据类型。
		//C++更趋向于使用迭代器而不是下标操作
		//因为标准库为每一种标准容器（如vector）定义了一种迭代器类型，而只用少数容器（如vector）支持下标操作访问容器元素。
		for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
			pri_que.push(*it);
			if (pri_que.size() > k) {
				//如果堆的大小大于k了，则队列弹出，保证堆的大小一直为k
				pri_que.pop();
			}
		}

		//找出前k个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
		vector<int> result(k);
		for (int i = k - 1; i >= 0; i--) {
			result[i] = pri_que.top().first;
			pri_que.pop();
		}
		return result;
	}
};

int main() {
	vector<int> str = { 1,1,1,4,4,5,6,7,5,5,6,3 };
	Solution s;
	int k = 3;
	vector<int> str1 = s.topKFrequent(str, k);
	for (int i = 0; i < str1.size(); i++) {
		cout << str1[i] << endl;
	}
}
