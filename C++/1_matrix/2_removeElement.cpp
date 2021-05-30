#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	int removeElement_simple(vector<int>& nums, int val)
	{
		int size = nums.size();
		for(int i=0;i<size;i++)
			if (nums[i] == val)
			{
				for (int j = i + 1; j < size; j++)
				{
					nums[j - 1] = nums[j];
				}
				i--;
				size--;
			}
		return size;
	}

	//双指针法
	int removeElement_point(vector<int>& nums, int val)
	{
		int slowIndex = 0;
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
		{
			if (val != nums[fastIndex])
			{
				nums[slowIndex++] = nums[fastIndex];
			}
		}
		return slowIndex;
	}
};

int main()
{
	vector<int> a = { -1,3,5,6,8 };
	int val = 2;
	cout << Solution().removeElement_point(a, val)<<endl;
	cout << Solution().removeElement_simple(a, val);
}
