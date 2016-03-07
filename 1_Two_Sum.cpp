#include <iostream>
#include <vector>
/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*
*You may assume that each input would have exactly one solution.
*
*Example:
*Given nums = [2, 7, 11, 15], target = 9,
*
*Because nums[0] + nums[1] = 2 + 7 = 9,
*return [0, 1].
*/
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int iC = nums.size();
        for(int i = 0; i < iC; i++)
        {
            if(!m.count(nums[i]))
            {
                m[target - nums[i]] = i; 
            }
            else
            {
                vector<int> v;
                v.push_back(m[nums[i]]);
                v.push_back(i);
                return v;
            }
        }
    }
};
