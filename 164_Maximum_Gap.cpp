#include <vector>
using namespace std;
//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//Try to solve it in linear time/space.
//Return 0 if the array contains less than 2 elements.
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int N = nums.size();
		if(N < 2) return 0;
		radixSort(nums);
		int max = 0;
		for(int i = 1; i < N; i++)
		{
			if(nums[i] - nums[i-1] > max) max = nums[i] - nums[i-1];
		}
		return max;
	}
private:
	void countSort(vector<int> &nums, const int iMax, const int bit)
	{
		vector<int> arrCount(iMax+1,0);
		for(auto &a : nums)
		{
			int t = (a/(int)pow(iMax+1,bit))%(iMax+1);
			arrCount[t]++;
		}
		for(int i = 1; i <= iMax; i++)
		{
			arrCount[i] += arrCount[i-1];
		}
		vector<int> ret(nums.size(),0);
		for(int i = nums.size() - 1; i >= 0; --i)
		{
			int temp = (nums[i]/(int)pow(iMax+1,bit))%(iMax+1);
			ret[arrCount[temp]-1] = nums[i];
			arrCount[temp]--;
		}
		nums = ret;
	}
	void radixSort(vector<int>& nums)
	{
		for(int k = 0; k < 4; k++)
		{
			countSort(nums, pow(2,8), k);
		}
	}
};
