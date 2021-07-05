#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> result_set;//存放结果
		unordered_set<int> nums_set(nums1.begin(), nums1.end());
		for (int num : nums2) {
			//发现nums2的元素在nums_set里又出现过
			if (nums_set.find(num) != nums_set.end()) {
				result_set.insert(num);
			}
		}
		return vector<int>(result_set.begin(), result_set.end());
	}
};

int main() {
	vector<int> nums1 = {1,2,3,1};
	vector<int> nums2 = { 2,4,2 };
	Solution s;
	vector<int> nums3 = s.intersection(nums1, nums2);
	for (int i = 0; i < nums3.size(); i++) {
		cout << nums3.at(i) << endl;
	}
}
