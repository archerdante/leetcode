#include <vector>
using namespace std;
//Given an unsorted array of integers, find the length of longest increasing subsequence.
//For example,
//Given [10, 9, 2, 5, 3, 7, 101, 18],
//The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//Your algorithm should run in O(n2) complexity.
//Follow up: Could you improve it to O(n log n) time complexity?
//Credits:
//Special thanks to @pbrother for adding this problem and creating all test cases.
//Subscribe to see which companies asked this question
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return 0;
        vector<int> temp = {nums[0]};
        for(auto a : nums)
        {
            if(a < temp.front()) temp.front() = a;
            else if(a > temp.back()) temp.push_back(a);
            else
            {
                int b = 0, e = temp.size(), mid = 0;
                while(b < e)
                {
                    mid = b + (e - b) / 2;
                    if(a <= temp[mid]) e = mid;
                    else b = mid + 1;
                }
                temp[e] = a;
            }
        }
        return temp.size();
    }
};
