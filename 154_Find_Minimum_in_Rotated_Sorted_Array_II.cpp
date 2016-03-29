#include <iostream>
#include <vector>
//Follow up for "Find Minimum in Rotated Sorted Array":
//What if duplicates are allowed?
//Would this affect the run-time complexity? How and why?
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//Find the minimum element.
//The array may contain duplicates.
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int b = 0, e = nums.size() - 1, mid = 0;
        while(b < e)
        {
            mid = b + (e - b) / 2;
            if(nums[mid] > nums[b]) 
            {
                if(nums[mid] > nums[e]) b = mid + 1;
                else return nums[b];
            }
            else if(nums[mid] < nums[b])
            {
                e = mid;
            }
            else
            {
                if(nums[mid] == nums[e]) b++;
                else if(nums[mid] > nums[e]) b = mid + 1;
                else return nums[b];
            }
        }
        return nums[b];
    }
};
