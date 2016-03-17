#include <iostream>
#include <vector>
#include <set>
//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//For example,
//[1,1,2] have the following unique permutations:
//[1,1,2], [1,2,1], and [2,1,1].
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        permute(nums,res,0,nums.size() - 1);
        return res;
    }
private:
    void permute(vector<int> &nums, vector<vector<int> > &res, int start, const int n)
    {
        if(start > n)
        {
            res.push_back(nums);
            return;
        }
        set<int> s;
        for(int i = start; i <= n; i++)
        {
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[start],nums[i]);
            permute(nums,res,start + 1,n);
            swap(nums[start],nums[i]);
        }
    }
    void swap(int &a, int &b)
    {
        if(a == b) return;
        a ^= b;
        b ^= a;
        a ^= b;
    }
};
