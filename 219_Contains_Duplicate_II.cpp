#include <iostream>
#include <vector>
//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int N = nums.size();
        int max = 0;
        for(int i = 0; i < N; i++)
        {
            if(m.count(nums[i]) && i - m[nums[i]] <= k)
            {
                return true;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
