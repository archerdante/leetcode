#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
    }
private:
    bool dfs(vector<vector<char> > &board, int pos)
    {
        if(pos == 81) return true;
        int m = pos / 9, n = pos % 9;
        if(board[m][n] == '.')
        {
            for(int i = 1; i <= 9; ++i)
            {
                if(check(board,pos,'0'+i))
                {
                    board[m][n] = '0'+i;
                    if(dfs(board, pos+1)) return true;
                    board[m][n] = '.';
                }
            }
        }
        else
        {
            if(dfs(board, pos+1)) return true;
        }
        return false;
    }
    bool check(vector<vector<char> > &board, int pos, char c)
    {
        int m = pos / 9, n = pos % 9;
        for(int i = 0; i < 9; ++i)
        {
            int x = 3*(m/3) + (i/3), y = 3*(n/3) + (i%3);
            if(board[m][i] == c || board[i][n] == c || board[x][y] == c) return false;
        }
        return true;
    }
};
