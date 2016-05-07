#include <vector>
using namespace std;
//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//f(n) = max(f(n-1),nums[n] + f(n-2))
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int fn_0 = 0, fn_1 = 0;
        for(auto a : nums)
        {
            int temp = fn_0;
            fn_0 = temp > fn_1 + a ? temp : fn_1 + a;
            fn_1 = temp;
        }
        return fn_0;
    }
};
