#include <vector>
using namespace std;
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example, 
//Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        if(N <= 2) return 0;
        int pl = 0, pr = N - 1, plmax = height[0], prmax = height[N-1], res = 0;
        while(pl < pr)
        {
            if(height[pl] <= height[pr])
            {
                while(height[++pl] < plmax) res+= plmax-height[pl];
                plmax = height[pl];
            }
            else
            {
                while(height[--pr] <= prmax) res+= prmax-height[pr];
                prmax = height[pr];
            }
        }
        return res;
    }
};
