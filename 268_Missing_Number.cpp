#include <vector>
using namespace std;
//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//For example,
//Given nums = [0, 1, 3] return 2.
//Note:
//Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
class Solution {
public:
int missingNumber(vector<int>& nums) {
int N = nums.size();
for(auto &a : nums)
{
while(a < N && a != nums[a]) swap(nums[a], a);
}
for(int i = 0; i < N; i++)
{
if(nums[i] != i) return i;
}
return N;
}
};
