#include <vector>
using namespace std;
//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//For example,
//If n = 4 and k = 2, a solution is:
//
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//]
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> temp;
        dfs(ret, temp, n, k, 1);
        return ret;
    }
private:
    void dfs(vector<vector<int> > &ret, vector<int> &temp, const int n, const int k, const int b)
    {
        if(temp.size() == k)
        {
            ret.push_back(temp);
            return;
        }
        for(int i = b; i <= n; ++i)
        {
            temp.push_back(i);
            dfs(ret, temp, n, k, i + 1);
            temp.pop_back();
        }
    }
};
