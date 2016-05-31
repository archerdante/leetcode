#include <vector>
using namespace std;
//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//Note: You can only move either down or right at any point in time.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        if(grid[0].empty()) return 0;
        const int M = grid.size();
        const int N = grid[0].size();
        vector<int> temp(M,INT_MAX);
        temp[0] = 0;
        for(int j = 0; j < N; ++j)
        {
            temp[0] += grid[0][j];
            for(int i = 1; i < M; ++i)
            {
                temp[i] = grid[i][j] + (temp[i-1] < temp[i] ? temp[i - 1] : temp[i]);
            }
        }
        return temp[M-1];
    }
};
