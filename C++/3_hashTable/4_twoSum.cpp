#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			auto iter = map.find(target - nums[i]);
			if (iter != map.end()) {
				return { iter->second,i };
			}
			map.insert(pair<int, int>(nums[i], i));
		}
		return {};
	}
};

int main() {
	vector<int> v = { 1,2,3,4,5 };
	int target = 9;
	Solution s;
	vector<int> a = s.twoSum(v, target);
	for (int i = 0; i < a.size(); i++) {
		cout <<"下标："<< a.at(i) << endl;
	}
}
