#include <iostream>
#include <vector>
//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//For example,
//Given the following matrix:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int rows = matrix.size();
        if(rows == 0) return ret;
        int colums = matrix[0].size();
        if(colums == 0) return ret;
        int start = 0;
        while(start * 2 < rows && start * 2 < colums)
        {
            spiralOneCircle(matrix, rows, colums, start, ret);
            start++;
        }
        return ret;
    }
private:
    void spiralOneCircle(const vector<vector<int>>& matrix, const int rows, const int colums, const int start, vector<int>& ret)
    {
        int endX = colums - 1 - start;
        int endY = rows - 1 -start;
        for(int i = start; i <= endX; i++)
        {
            ret.push_back(matrix[start][i]);
        }
        if(endY > start)
        {
            for(int i = start + 1; i <= endY; i++)
            {
                ret.push_back(matrix[i][endX]);
            }
        }
        if(endY > start && endX > start)
        {
            for(int i = endX - 1; i >= start; i--)
            {
                ret.push_back(matrix[endY][i]);
            }
        }
        if(endY > start + 1 && endX > start)
        {
            for(int i = endY - 1; i > start; i--)
            {
                ret.push_back(matrix[i][start]);
            }
        }
    }
};
