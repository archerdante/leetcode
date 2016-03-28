#include <iostream>
//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed?
//Would this affect the run-time complexity? How and why?
//Write a function to determine if a given target is in the array.
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int b = 0;
        int e = nums.size() - 1;
        while(b <= e)
        {
            int mid = b + (e - b) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] > nums[b])
            {
                if(target < nums[mid] && target >= nums[b])
                {
                    e = mid - 1;
                }
                else
                {
                    b = mid + 1;
                }
            }
            else if(nums[mid] < nums[b])
            {
                if(target > nums[mid] && target <= nums[e])
                {
                    b = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            else
            {
                b++;
            }
        }
        return false;
    }
};
