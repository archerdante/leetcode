#include <vector>
using namespace std;
//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.
//
//Subscribe to see which companies asked this question
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxp = nums[0], minp = nums[0], res = nums[0];
        int N = nums.size();
        for(int i = 1; i < N; ++i)
        {
            maxp *= nums[i];
            minp *= nums[i];
            if(maxp < minp) swap(maxp, minp);
            if(nums[i] > maxp) maxp = nums[i];
            if(nums[i] < minp) minp = nums[i];
            if(maxp > res) res = maxp;
        }
        return res;
    }
};
