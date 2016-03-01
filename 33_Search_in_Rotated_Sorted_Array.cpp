#include <iostream>
#include <vector>
/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Subscribe to see which companies asked this question
 */
using namespace std;
class Solution 
{
	public:
    int search(vector<int>& nums, int target) 
	{
		int b = 0, e = nums.size() - 1;    
        while(b <= e)
        {   
            const int mid = b + (e - b) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[b])  //这个等号很关键，没有则出错，也可以把相等的情况单列出了考虑
            {   
                if(nums[b] <= target && target < nums[mid])
                    e = mid - 1;
                else 
                    b = mid + 1;
            }   
            else
            {   
                if(nums[mid] < target && target <= nums[e])
                    b = mid + 1;
                else 
                    e = mid - 1;
            }   
        }   
        return -1;
    }
};
int main()
{}
