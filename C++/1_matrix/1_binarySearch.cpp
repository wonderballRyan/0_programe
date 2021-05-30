#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	//左闭右闭区间
	int search1(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size()-1;
		while (left<=right)
		{
			int middle = left + ((right - left) /2);
			if (nums[middle] > target)
			{
				right = middle - 1;
			}
			else if (nums[middle]<target)
			{
				left = middle + 1;
			}
			else
			{
				return middle;
			}
		}
		//未找到目标
		return -1;
	}

	//左闭右开区间
	int search2(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size();
		while (left < right)
		{
			int middle = left + ((right - left) >> 2);
			if (nums[middle] > target)
			{
				right = middle;
			}
			else if(nums[middle]<target)
			{
				left = middle + 1;
			}
			else
			{
				return middle;
			}
		}
		return -1;
	}
};

int main()
{
	vector<int> a = { -1, 0, 3, 5, 9, 12 };
	int target = 9;
	Solution s;
	cout<<s.search1(a, target)<<endl;

	cout << s.search2(a, target);
}
