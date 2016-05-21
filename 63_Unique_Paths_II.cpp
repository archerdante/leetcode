#include <vector>
using namespace std;
//Follow up for "Unique Paths":
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//For example,
//There is one obstacle in the middle of a 3x3 grid as illustrated below.
//[
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
//]
//The total number of unique paths is 2.
//Note: m and n will be at most 100.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        if(obstacleGrid[0].empty()) return 0;
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[M-1][N-1]) return 0;
        vector<int> temp;
        int k = 1, s = 1;
        for(auto &a :obstacleGrid[0])
        {
            if(a == 1) k = 0;
            temp.push_back(k);
        }
        for(int i = 1; i < M; ++i)
        {
            if(obstacleGrid[i][0] == 1) s = 0;
            temp[0] = s;
            for(int j = 1; j < N; ++j)
            {
                temp[j] = (obstacleGrid[i][j - 1] == 0 ? temp[j-1] : 0) + (obstacleGrid[i-1][j] == 0 ? temp[j] : 0);
            }
        }
        return temp[N-1];
    }
};
