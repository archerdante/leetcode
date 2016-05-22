#include <vector>
using namespace std;
//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//For example, given array S = {-1 2 1 -4}, and target = 1.
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        if(N <= 2) return 0;
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[N-1];
        int min = abs(target - sum);
        for(int i = 0; i < N - 2; ++i)
        {
            int newTarget = target - nums[i];
            twoSumClosest(nums, newTarget, nums[i], i + 1, N, min, sum);
        }
        return sum;
    }
private:
    void twoSumClosest(vector<int> &nums, int target, const int p, const int begin, const int N, int &min, int &sum)
    {
        int b = begin, e = N - 1;
        while(b < e)
        {
            while(b < e && nums[b] + nums[e] >= target + min) --e;
            while(b < e && nums[b] + nums[e] <= target - min) ++b;
            if(b < e && abs(nums[b] + nums[e] - target) < min) 
            {
                min = abs(nums[b] + nums[e] - target);
                sum = nums[b] + nums[e] + p;
            }
        }
    }
};
