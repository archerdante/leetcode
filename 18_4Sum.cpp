#include <vector>
using namespace std;
//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note:
//Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
//The solution set must not contain duplicate quadruplets.
//    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
//
//    A solution set is:
//    (-1,  0, 0, 1)
//    (-2, -1, 1, 2)
//    (-2,  0, 0, 2)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        int N = nums.size();
        if(N < 4) return ret;
        int a = 0, b = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= N - 4; ++i)
        {
            a = nums[i];
            int tempT3 = target - a;
            for(int j = i + 1; j <= N - 3; ++j)
            {
                b = nums[j];
                int tempT2 = tempT3-b;
                if((tempT2 < nums[j+1] + nums[j+2])) break;  //import to improve speed
                int begin = j + 1, end = N - 1;
                while(begin < end)
                {
                    if((tempT2 > nums[end] + nums[end-1])) break;  //import to improve speed
                    while(begin < end && nums[begin] + nums[end] < tempT2) begin++;
                    while(begin < end && nums[begin] + nums[end] > tempT2) end--;
                    if(begin < end && nums[begin] + nums[end] == tempT2)
                    {
                        vector<int> tv = {a,b,nums[begin],nums[end]};
                        ret.push_back(tv);
                        while(begin + 1 <= end && nums[begin] == nums[begin+1]) begin++;
                        while(end - 1 >= begin && nums[end] == nums[end - 1]) end--;
                        begin++;
                        end--;
                    }
                }
                while(j + 1 <= N - 3 && nums[j + 1] == nums[j]) j++;
            }
            while(i + 1 <= N - 4 && nums[i + 1] == nums[i]) i++;
        }
        return ret;
    }
};
