#include <vector>
using namespace std;
//You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
//Example 1:
//coins = [1, 2, 5], amount = 11
//return 3 (11 = 5 + 5 + 1)
//
//Example 2:
//coins = [2], amount = 3
//return -1.
//
//Note:
//You may assume that you have an infinite number of each kind of coin.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int min = INT_MAX;
        dfs(coins, amount, coins.size() - 1,0,min);
        return min == INT_MAX ? -1 : min;
    }
private:
    void dfs(vector<int> &coins, const int amount, const int end, int nums, int &min)
    {
        if(end < 0) return;
        int i = amount / coins[end];
        if((amount % coins[end]) == 0) 
        {
            min = nums + i < min ? nums + i : min;
        }
        for(; i >= 0; --i)
        {
            if(nums + i > min) break;
            dfs(coins, amount - i * coins[end], end - 1, nums + i, min);
        }
    }
};
