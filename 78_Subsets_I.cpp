#include <vector>
using namespace std;
//Given a set of distinct integers, nums, return all possible subsets.
//
//Note:
//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If nums = [1,2,3], a solution is:
//
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        const int N = nums.size();
        vector<vector<int> > ret;
        int temp = pow(2, N);
        for(int i = temp - 1; i >=0; i--)
        {
            ret.push_back(getOneByTemp(nums, N, i));
        }
        return ret;
    }
private:
    vector<int> getOneByTemp(const vector<int> &nums, const int N,const int temp)
    {
        vector<int> oneLine;
        for(int i = 0; i < N; i++)
        {
            if((1 << i) & temp)
            {
                oneLine.push_back(nums[i]);
            }
        }
        return oneLine;
    }
};
