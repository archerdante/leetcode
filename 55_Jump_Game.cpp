#include <iostream>
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false.
//
//Subscribe to see which companies asked this question
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fartest = nums[0];
        int i = 0;
        for(auto a : nums)
        {
            if(fartest < i) return false;
            if(a + i > fartest) fartest = a + i;
            i++;
        }
        return true;
    }
};
