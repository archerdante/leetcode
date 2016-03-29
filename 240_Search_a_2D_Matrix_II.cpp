#include <iostream>
#include <vector>
//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.
//For example,
//
//Consider the following matrix:\<F11
//[
//	[1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
//Given target = 5, return true.
//
//Given target = 20, return false.
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) return false;
        int colums = matrix[0].size(); 
        if(colums == 0) return false;
        int i = 0, j = colums - 1;
        while(i < rows && j >= 0)
        {
            if(target == matrix[i][j]) return true;
            while(j >= 0 && matrix[i][j] > target) j--;
            while(j >= 0 && i < rows && matrix[i][j] < target) i++;
        }
        return false;
    }
};
