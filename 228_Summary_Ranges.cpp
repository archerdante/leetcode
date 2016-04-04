#include <iostream>
#include <string>
#include <vector>
//Given a sorted integer array without duplicates, return the summary of its ranges.
//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int N = nums.size();
        if(N == 0) return ret;
        int from = 0;
        for(int i = 1; i <= N; i++)
        {
            if(i == N || nums[i-1] + 1 != nums[i])
            {
                string s;
                if(i - 1 == from)
                {
                    s.append(to_string(nums[i - 1]));
                }
                else
                {
                    s.append(to_string(nums[from]));
                    s.append("->");
                    s.append(to_string(nums[i - 1]));
                }
                ret.push_back(s);
                from = i;
            }
        }
        return ret;
    }
};
