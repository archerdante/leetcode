#include <vector>
using namespace std;
//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
//You may assume that the array is non-empty and the majority element always exist in the array.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int iCount = 1, iTemp = nums[0];
        for(vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it)
        {
            if(*it != iTemp)
            {
                if(--iCount == 0) {iTemp = *it;iCount = 1;}
            }
            else
            {
                ++iCount;
            }
        }
        return iTemp;
    }
};
