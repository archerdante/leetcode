#include <iostream>
#include <vector>
//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//Note: You may not slant the container.
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        if(N < 2) return -1;
        int left = 0, right = N - 1, max = 0;
        while(left < right)
        {
            int h = height[left] < height[right] ? height[left] : height[right];
            int temp = h * (right - left);
            max = temp > max ? temp : max;
            if(height[left] > height[right]) right--;
            else left++;
        }
        return max;
    }
};
