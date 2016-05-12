#include <vector>
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example:
//Given array A = [2,3,1,1,4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note:
//You can assume that you can always reach the last index.
using namespace std;
class Solution {
public:
    bool jump(vector<int>& nums) {
        int N = nums.size();
        vector<int> record(N,0);
        return dfs(nums, record, 0, N - 1);
    }
private:
    bool dfs(vector<int> &nums, vector<int> &record,const int start, const int N)
    {
        if(start == N) 
        {
            record[start] = 1;
            return true;
        }
        if(start > N)return false;
        if(record[start] == -1) return false;
        else
        {
            if(nums[start] == 0)
            {
                record[start] = -1;
                return false;
            }
            else
            {
                for(int i = nums[start]; i > 0; i--)
                {
                    if(dfs(nums, record, start + i, N))
                    {
                        return true;
                    }
                }

            }
        }
        record[start] = -1;
        return false;
    }
};
