#include <vector>
using namespace std;
//After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> v_1 = vector<int>(nums.begin()+1,nums.end());
        vector<int> v_2 = vector<int>(nums.begin(),nums.end()-1);
        return max(robNoCircle(v_1), robNoCircle(v_2));
    }
private:
    int robNoCircle(vector<int> &nums)
    {
        int f_0 = 0, f_1 = 0;
        for(auto &a : nums)
        {
            int temp = f_0;
            if(f_1 + a > f_0) f_0 = f_1 + a;
            f_1 = temp;
        }
        return f_0;
    }
};
