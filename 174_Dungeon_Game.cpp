#include <vector>
using namespace std;
//The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
//
//The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
//
//Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
//
//In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//
//
//Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
//
//For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
//
//-2 (K)	-3	3
//-5	-10	1
//10	30	-5 (P)
//
//Notes:
//
//The knight's health has no upper bound.
//Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()) return 1;
        if(dungeon[0].empty()) return 1;
        int M = dungeon.size(), N = dungeon[0].size();
        vector<int> temp(M,0);
        if(dungeon[M-1][N-1]>=0) temp[M-1] = 1;
        else temp[M-1] = 1-dungeon[M-1][N-1];
        for(int k = M - 2; k >=0; --k)
        {
            if(dungeon[k][N-1] >= temp[k+1]) temp[k] = 1;
            else temp[k] = temp[k+1]-dungeon[k][N-1];
        }
        for(int j = N - 2; j >= 0; --j)
        {   if(dungeon[M-1][j] >= temp[M-1]) temp[M-1] = 1;
            else temp[M-1] = temp[M-1]-dungeon[M-1][j];
            for(int i = M - 2; i >= 0; --i)
            {
                int minLife = min(temp[i],temp[i+1]);
                if(dungeon[i][j] >= minLife) temp[i] = 1;
                else temp[i] = minLife-dungeon[i][j];
            }
        }
        return temp[0];
    }
};
