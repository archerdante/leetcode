#include <vector>
using namespace std;
//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//11110
//11010
//11000
//00000
//Answer: 1
//
//Example 2:
//
//11000
//11000
//00100
//00011
//Answer: 3
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int M = grid.size();
        if(grid[0].empty()) return 0;
        int N = grid[0].size();
        int ret = 0;
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(grid[i][j] == '1') ++ret, searchEdge(grid, i, j, M, N);
            }
        }
        return ret;
    }
private:
    void searchEdge(vector<vector<char> > &grid, const int i, const int j, const int M, const int N)
    {
        grid[i][j] = '#';
        if(i > 0 && grid[i - 1][j] == '1') searchEdge(grid, i - 1, j, M, N);
        if(i < M - 1 && grid[i + 1][j] == '1') searchEdge(grid, i + 1, j, M, N);
        if(j > 0 && grid[i][j - 1] == '1') searchEdge(grid, i, j - 1, M, N);
        if(j < N - 1 && grid[i][j + 1] == '1') searchEdge(grid, i, j + 1, M, N);
    }
};
