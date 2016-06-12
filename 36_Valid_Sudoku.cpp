#include <vector>
using namespace std;
//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//Note:
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i)
        {
            unordered_set<char> set_i;
            unordered_set<char> set_j;
            unordered_set<char> set_k;
            for(int j = 0; j < 9; ++j)
            {
                char char_i = board[i][j];
                if(char_i != '.')
                {
                    if(set_i.count(char_i)) return false;
                    set_i.insert(char_i);
                }
                char char_j = board[j][i];
                if(char_j != '.')
                {
                    if(set_j.count(char_j)) return false;
                    set_j.insert(char_j);
                }
                char char_k = board[(i/3)*3 + (j/3)][(i%3)*3 + (j%3)];
                if(char_k != '.')
                {
                    if(set_k.count(char_k)) return false;
                    set_k.insert(char_k);
                }
            }
        }
        return true;
    }
};
