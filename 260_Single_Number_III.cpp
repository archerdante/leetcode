#include <vector>
using namespace std;
//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
//For example:
//
//Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//
//Note:
//The order of the result is not important. So in the above example, [5, 3] is also correct.
//Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
class Solution {
public:
vector<int> singleNumber(vector<int>& nums) {
	vector<int> ret(2,0);
	int diff = 0;
	for(auto &a : nums)
	{
		diff ^= a;
	}
	diff &= ~(diff - 1);
	for(auto &a : nums)
	{
		if(diff & a)
		{
			ret[0] ^= a;
		}
		else
		{
			ret[1] ^= a;
		}
	}
	return ret;
	}
};
