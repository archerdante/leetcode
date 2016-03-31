#include <iostream>
#include <vector>
//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//For example,
//Given n = 3,
//You should return the following matrix:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//]
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> rowVector(n, 0);
        vector<vector<int> > matrix(n, rowVector); 
        int start = 0, index = 1;
        while(start * 2 < n)
        {
            generateOneCircle(matrix, n, start++, index);
        }
        return matrix;
    }
private:
    void generateOneCircle(vector<vector<int> > &matrix, const int n, const int start, int &index)
    {
        int end = n- 1 - start ;
        for(int i = start; i <= end; i++)
        {
            matrix[start][i] = index++;
        }
        if(end > start)
        {
            for(int i = start + 1; i <= end; i++)
            {
                matrix[i][end] = index++;
            }
            for(int i = end - 1; i >= start; i--)
            {
                matrix[end][i] = index++;
            }
        }
        if(end > start + 1)
        {
            for(int i = end - 1; i > start; i--)
            {
                matrix[i][start] = index++;
            }
        }
    }
};
