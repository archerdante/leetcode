#include <vector>
#include <string>
using namespace std;
//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//word = "ABCCED", -> returns true,
//word = "SEE", -> returns true,
//word = "ABCB", -> returns false.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()|| word.empty()) return false;
        M = board.size();
        N = board[0].size();
        Q = word.size();
        vector<vector<bool> > record(M,vector<bool>(N, false));
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                int k = 0;
                if(search(board, record, word, i, j, k)) return true;
            }
        }
        return false;
    }
private:
    int M = 0;
    int N = 0;
    int Q = 0;
    bool search(vector<vector<char> > &board, vector<vector<bool> > &record, string &word, const int i,const int j, const int k)
    {
        if(k == Q - 1 && word[k] == board[i][j]) return true;
        if(k >= Q) return false;
        if(board[i][j] != word[k]) return false;
        else
        {
            record[i][j] = true;
            if(i > 0 && !record[i-1][j] && search(board,record,word,i-1,j,k+1)) return true;
            if(i < M - 1 && !record[i+1][j] && search(board,record,word,i+1,j,k+1)) return true;
            if(j > 0 && !record[i][j-1] && search(board,record,word,i,j-1,k+1)) return true;
            if(j < N - 1 && !record[i][j+1] && search(board,record,word,i,j+1,k+1)) return true;
            record[i][j] = false;
            return false;
        }
    }
};
