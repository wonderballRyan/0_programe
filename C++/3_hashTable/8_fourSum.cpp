#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int k = 0; k < nums.size(); k++) {
			if (k > 0 && nums[k] == nums[k - 1]) {
				continue;
			}
			for (int i = k + 1; i < nums.size(); i++) {
				//正确去重方法
				if (i > k + 1 && nums[i] == nums[i - 1]) {
					continue;
				}
				int left = i + 1;
				int right = nums.size() - 1;
				while (right > left) {
					if (nums[k] + nums[i] + nums[left] + nums[right] > target) {
						right--;
					}
					else if (nums[k] + nums[i] + nums[left] + nums[right] < target) {
						left++;
					}
					else {
						result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
						while (right > left && nums[right] == nums[right - 1]) right--;
						while (right > left && nums[left] == nums[left + 1]) left++;

						//找到答案时，双指针同时收缩
						right--;
						left++;
					}
				}
			}
		}
		return result;
	}
		
};
int main() {
	vector<int> a = {-5,-2,1,5,6,-3,-2,3,2,1,-3};
	Solution s;
	vector<vector<int>> b = s.fourSum(a,0);
	for (int i = 0; i < b.size(); i++) {
		cout << "[";
		for (int j = 0; j < b[i].size(); j++) {
			cout << b[i][j] << ",";
		}
		cout << "]" << endl;
	}

}
