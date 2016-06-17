#include <vector>
using namespace std;
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
//Note:
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if(N <= 1) return 0;
        int minn = prices[0];
        vector<int> preRecord(N,0);
        for(int i = 1; i < N;++i)
        {
            if(prices[i] < minn) minn = prices[i];
            if(prices[i] - minn > preRecord[i-1]) preRecord[i] = prices[i] - minn;
            else preRecord[i] = preRecord[i-1];
        }
        int maxx = prices[N-1];
        vector<int> postRecord(N,0);
        for(int i = N-2; i >= 0;--i)
        {
            if(prices[i] > maxx) maxx = prices[i];
            if(maxx - prices[i] > postRecord[i+1]) postRecord[i] = maxx - prices[i];
            else postRecord[i] = postRecord[i+1];
        }
        int ret = 0;
        for(int i = 0; i < N;++i)
        {
            if(preRecord[i] + postRecord[i] > ret) ret = preRecord[i] + postRecord[i];
        }
        return ret;
    }
};
