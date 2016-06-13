#include <vector>
using namespace std;
//Given an integer matrix, find the length of the longest increasing path.
//
//From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
//Example 1:
//
//nums = [
//  [9,9,4],
//  [6,6,8],
//  [2,1,1]
//]
//Return 4
//The longest increasing path is [1, 2, 6, 9].
//
//Example 2:
//
//nums = [
//  [3,4,5],
//  [3,2,6],
//  [2,2,1]
//]
//Return 4
//The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        if(matrix[0].empty()) return 0;
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int> > memoize = vector<vector<int> >(M,vector<int>(N,0));
        int ret = 0;
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(memoize[i][j] == 0) 
                {
                    int temp = dfs(matrix,memoize,i,j,M,N);
                    if(temp > ret) ret = temp;
                }
            }
        }
        return ret;
    }
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memoize,const int i, const int j,const int M, const int N)
    {
        if(memoize[i][j] != 0) return memoize[i][j];
        int temp = 1;
        if(i > 0 && matrix[i-1][j] > matrix[i][j]) temp = max(temp,dfs(matrix,memoize,i-1,j,M,N)+1);
        if(i < M - 1&& matrix[i+1][j] > matrix[i][j]) temp = max(temp,dfs(matrix,memoize,i+1,j,M,N)+1);
        if(j > 0&& matrix[i][j-1] > matrix[i][j]) temp = max(temp,dfs(matrix,memoize,i,j-1,M,N)+1);
        if(j < N - 1&& matrix[i][j+1] > matrix[i][j]) temp = max(temp,dfs(matrix,memoize,i,j+1,M,N)+1);
        memoize[i][j] = temp;
        return temp;
    }
};
