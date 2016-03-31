#include <iostream>
#include <vector>
//Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//The same repeated number may be chosen from C unlimited number of times.
//Note:
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//For example, given candidate set 2,3,6,7 and target 7, 
//A solution set is: 
//[7] 
//[2, 2, 3]
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int N = candidates.size();
        vector<vector<int> > ret;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        combinationOne(candidates, target, 0, N, ret, path);
        return ret;
    }
private:
    void combinationOne(const vector<int>& candidates, const int target, const int start, const int N, vector<vector<int>> &ret, vector<int> path)
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
            for(int i = start; i < N; i++)
            {
                path.push_back(candidates[i]);
                combinationOne(candidates, target - candidates[i], i, N, ret, path);
                path.pop_back();
            }
        }
    }
};
