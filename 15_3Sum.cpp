#include <vector>
using namespace std;
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//The solution set must not contain duplicate triplets.
//    For example, given array S = {-1 0 1 2 -1 -4},
//
//        A solution set is:
//            (-1, 0, 1)
//            (-1, -1, 2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size() <=2) return ret;
        sort(nums.begin(), nums.end());
        for(vector<int>::iterator it = nums.begin(); it != nums.end() - 2 && (*it) <= 0; ++it)
        {
            if(it != nums.begin() && (*it) == (*(it-1))) continue;
            int sum = -(*it);
            vector<int>::iterator b = it + 1;
            vector<int>::iterator e = nums.end() - 1;
            while(b < e)
            {
                int temp = (*b) + (*e);
                if(temp < sum)
                {
                    b++;
                }
                else if(temp > sum)
                {
                    e--;
                }
                else
                {
                    vector<int> one = {*it,*b,*e}; 
                    ret.push_back(one);
                    while(b < e && (*b) == (*(b+1))) b++;
                    while(b < e && (*e) == (*(e-1))) e--;
                    b++;
                    e--;
                }
            }
        }
        return ret;
    }
};
