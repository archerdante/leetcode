#include <vector>
using namespace std;
//There are N children standing in a line. Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements:
//
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give?
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        if(N == 0) return 0;
        vector<int> candy(N, 1);
        for(int i = 1; i < N; ++i)
        {
            if(ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;
        }
        int ret = candy[N - 1];
        for(int i = N - 2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) candy[i] = candy[i + 1] + 1;
            ret += candy[i];
        }
        return ret;
    }
};
