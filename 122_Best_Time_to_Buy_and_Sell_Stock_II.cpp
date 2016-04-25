#include <vector>
using namespace std;
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        bool canBuy = true;
        int temp = 0;
        int sum = 0;
        for(vector<int>::iterator it = prices.begin(); it != prices.end() - 1; ++it)
        {
            if(canBuy && (*it) < *(it + 1))
            {
                temp = *it;
                canBuy = false;
            }
            else if(!canBuy && (*it) > *(it + 1))
            {
                sum += (*it) - temp;
                canBuy = true;
            }
        }
        if(!canBuy) sum+= *(prices.end() - 1) - temp;
        return sum;
    }
};
