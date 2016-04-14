#include <iostream>
#include <vector>
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//Follow up:
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if(M == 0) return;
        int N = matrix[0].size();
        if(N == 0) return;
		//use firstrow and firstcol to mark --> O(1) space
        int firstRow = false;
        int firstCol = false;
        for(int i = 0; i < M; i++)
        {
            if(matrix[i][0] == 0)
            {
                firstCol = true;
                break;
            }
        }
        for(int j = 0; j < N; j++)
        { 
            if(matrix[0][j] == 0)
            {
                firstRow = true;
                break;
            }
        }
        for(int i = 1; i < M; i++)
        {
            for(int j = 1; j < N; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < M; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 1; j < N; j++) matrix[i][j] = 0;
            }
        }
        for(int j = 1; j < N; j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 1; i < M; i++) matrix[i][j] = 0;
            }
        }
        if(firstRow)
        {
            for(int j = 0; j < N; j++) matrix[0][j] = 0;
        }
        if(firstCol)
        {
            for(int i = 0; i < M; i++) matrix[i][0] = 0;
        }
    }
};
