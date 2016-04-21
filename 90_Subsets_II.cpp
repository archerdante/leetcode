#include <vector>
using namespace std;
//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//Note:
//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If nums = [1,2,2], a solution is:
//
//[
//	[2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//]
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ret;
        vector<int> path;
        dfs(nums, ret, path, nums.begin());
        return ret;
    }
private:
    void dfs(vector<int> &nums, vector<vector<int> > &ret, vector<int> &path, vector<int>::iterator b)
    {
        ret.push_back(path);
        for(vector<int>::iterator it = b; it != nums.end(); it++)
        {
            if(it == b || (*it) != (*(it - 1)))
            {
                path.push_back(*it);
                dfs(nums, ret, path, it + 1);
                path.pop_back();
            }
        }
    }
};
