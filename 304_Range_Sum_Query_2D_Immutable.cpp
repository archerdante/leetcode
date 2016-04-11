#include <iostream>
#include <vector>
//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
//Given matrix = [
//[3, 0, 1, 4, 2],
//[5, 6, 3, 2, 1],
//[1, 2, 0, 1, 5],
//[4, 1, 0, 1, 7],
//[1, 0, 3, 0, 5]
//]
//
//sumRegion(2, 1, 4, 3) -> 8
//sumRegion(1, 1, 2, 2) -> 11
//sumRegion(1, 2, 2, 4) -> 12
//Note:
//You may assume that the matrix does not change.
//There are many calls to sumRegion function.
//You may assume that row1 ≤ row2 and col1 ≤ col2.
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        M = matrix.size();
        if(M == 0) return;
        N = matrix[0].size();
        if(N == 0) return;
        myMatrix = vector<vector<int> >(M, vector<int>(N,0));
        for(int i = 0; i < M; i++)
        {
            int lineSum = 0;
            for(int j = 0; j < N; j++)
            {
                int tempSum = 0;
                lineSum += matrix[i][j];
                tempSum = lineSum + (i - 1 >= 0 ? myMatrix[i - 1][j] : 0);
                myMatrix[i][j] = tempSum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(M == 0 || N == 0) return 0;
        int sum = myMatrix[row2][col2];
        if(row1 == 0 && col1 == 0) return sum;
        if(row1 == 0)
        {
            sum -= myMatrix[row2][col1 - 1];
        }
        else if(col1 == 0)
        {
            sum -= myMatrix[row1 - 1][col2];
        }
        else
        {
            sum -= myMatrix[row2][col1 - 1];
            sum -= myMatrix[row1 - 1][col2];
            sum += myMatrix[row1 - 1][col1 - 1];
        }
        return sum;
    }
private:
    vector<vector<int> > myMatrix;
    int M;
    int N;
};


// Your NumMatrix object will be instantiated and called as such:
// // NumMatrix numMatrix(matrix);
// // numMatrix.sumRegion(0, 1, 2, 3);
// // numMatrix.sumRegion(1, 2, 3, 4);
