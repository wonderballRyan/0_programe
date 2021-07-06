#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> umap;//key:a+b的数值，value:a+b数值出现的次数
		//遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
		for (int a : A) {
			for (int b : B) {
				umap[a + b]++;
			}
		}
		int count = 0;//统计a+b+c+d=0出现的次数
		//在遍历大C和大D数组，找到如果0-（c+d）在map中出现过的话，就把map中key对应的value也就是出现次数统计出来
		for (int c : C) {
			for (int d : D) {
				if (umap.find(0 - (c + d)) != umap.end()) {
					count += umap[0 - (c + d)];
				}
			}
		}
		return count;
	}
};

int main() {
	vector<int> a = { 0,1,-2 };
	vector<int> b = { -1,1,0 };
	vector<int> c = { 3,1,2 };
	vector<int> d = { -2,1,-3 };
	Solution s;
	cout << s.fourSumCount(a, b, c, d) << endl;
}
