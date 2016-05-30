#include <vector>
using namespace std;
//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
//
//For example, given the following matrix:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 4.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int max = 0;
        const int M = matrix.size();
        const int N = matrix[0].size();
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    int temp = dfs(matrix, i, j, M, N);
                    if(temp > max) max = temp;
                }
            }
        }
        return max*max;
    }
private:
    int dfs(vector<vector<char> > &matrix, const int r, const int c,const int M, const int N)
    {
        int num = 1, i = r, j = c;
        while((++i) < M && (++j) < N && matrix[i][j] == '1')
        {
            for(int k = 1; k <= i - r; ++k)
            {
                if(matrix[i][j - k] != '1') return num;
                if(matrix[i - k][j] != '1') return num;
            }
            ++num;
        }
        return num;
    }
};
