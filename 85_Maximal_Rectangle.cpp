#include <vector>
using namespace std;
//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        const int M = matrix.size();
        if(matrix[0].empty()) return 0;
        const int N = matrix[0].size();
        int ret = 0;
        vector<int> line(N+1, 0);
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                line[j] = matrix[i][j] == '0' ? 0 : line[j] + 1;
            }
            int temp = getMaxLineRect(line, N);
            if(temp > ret) ret = temp;
        }
        return ret;
    }
private:
    int getMaxLineRect(vector<int> &line, const int N)
    {
        stack<int> series;
        int ret = 0;
        for(int i = 0; i < N+1; ++i)
        {
            while(!series.empty() && line[series.top()] > line[i])
            {
                int h = line[series.top()];
                series.pop();
                int temp = h * (series.empty() ? i : (i - series.top() - 1));
                if(temp > ret) ret = temp;
            }
            series.push(i);
        }
        return ret;
    }
};
