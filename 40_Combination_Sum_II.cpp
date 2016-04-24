#include <vector>
using namespace std;
//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
//A solution set is: 
//[1, 7] 
//[1, 2, 5] 
//[2, 6] 
//[1, 1, 6] 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ret;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(ret, path, candidates, candidates.size(), target, 0);
        return ret;
    }
private:
    void dfs(vector<vector<int> > &ret, vector<int> &path, const vector<int> &candidates, const int &N, const int& target, const int& start)
    {
        if(target == 0)
        {
            ret.push_back(path);
            return;
        }
        else if(target < 0)
        {
            return;
        }
        else
        {
            for(int i = start; i < N; ++i)
            {
                if(i > start && candidates[i] == candidates[i - 1]) continue;
                path.push_back(candidates[i]);
                dfs(ret, path, candidates, N, target - candidates[i], i + 1);
                path.pop_back();
            }
        }
    }
};
