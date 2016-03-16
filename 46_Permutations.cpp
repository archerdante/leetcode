#include <iostream>
//Given a collection of distinct numbers, return all possible permutations.
//For example,
//[1,2,3] have the following permutations:
//[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
//         ABC
//  ABC    BAC    CBA
//ABC ACB BAC BCA CBA CAB
using namespace std;
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        getAllPermutations(res,nums,0,nums.size() - 1);
        return res;
    }
private:
    void getAllPermutations(vector<vector<int> > &res, vector<int> &nums, int start,const int n)
    {
        if(start > n)
        {
            res.push_back(nums);
            return;
        }
        else
        {
            for(int i = start; i <= n; i++)
            {
                swap(nums[start],nums[i]);
                getAllPermutations(res,nums,start + 1,n);
                swap(nums[start],nums[i]);
            }
        }
    }
    void swap(int &a, int &b)
    {
        if(a == b) return;
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};
