#include <iostream>
#include <vector>
using namespace std;
//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//Formally the function should:
//Return true if there exists i, j, k 
//such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
//Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//Examples:
//Given [1, 2, 3, 4, 5],
//return true.
//
//Given [5, 4, 3, 2, 1],
//return false.
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return 0;
        vector<int> temp = {nums[0]};
        for(auto a : nums)
        {
            if(a < temp.front()) temp.front() = a;
            else if(a > temp.back()) 
            {
                temp.push_back(a);
                if(temp.size() == 3) return true;
            }
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
        return false;
    }
};
