#include <vector>
using namespace std;
//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given heights = [2,1,5,6,2,3],
//return 10.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        stack<int> series;
        heights.push_back(0);
        int N = heights.size();
        int ret = 0;
        for(int i = 0; i < N; ++i)
        {
            if(series.empty() || heights[series.top()] <= heights[i])
            {
                series.push(i);
            }
            else
            {
                while(!series.empty() && heights[series.top()] > heights[i])
                {
                    int index = series.top();
                    series.pop();
                    int temp = (series.empty() ? i : (i - series.top() - 1)) * heights[index];
                    if(temp > ret) ret = temp;
                }
                series.push(i);
            }
        }
        return ret;
    }
};
