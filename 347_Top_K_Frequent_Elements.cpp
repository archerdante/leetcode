#include <vector>
#include <unordered_map>
using namespace std;
//Given a non-empty array of integers, return the k most frequent elements.
//
//For example,
//Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        ret.reserve(k);
        if(nums.empty()) return ret;
        unordered_map<int, int> myMap;
        for(auto &a : nums)
        {
            myMap[a]++;
        }
        unordered_map<int, int>::iterator it = myMap.begin();
        vector<pair<int,int>> myVec;
        int i = 0;
        while(it != myMap.end() && i < k)
        {
            myVec.push_back(*it++);
            i++;
        }
        const int N = myVec.size();
        buildMinHeap(myVec, N);
        while(it != myMap.end())
        {
            if(it->second > myVec[0].second)
            {
                myVec[0] = *it;
                minHeap(myVec, 0, N);
            }
            it++;
        }
        for(auto &c : myVec)
        {
            ret.push_back(c.first);
        }
        return ret;
    }
private:
    inline int left(const int i)
    {
        return (i<<1)|1;
    }
    inline int right(const int i)
    {
        return (i+1)<<1;
    }
    void minHeap(vector<pair<int,int>> &nums, const int node, const int N)
    {
        int l = left(node), r = right(node), minn = node;
        if(l < N && nums[l].second < nums[minn].second) minn = l;
        if(r < N && nums[r].second < nums[minn].second) minn = r;
        if(minn != node)
        {
            swap(nums[minn],nums[node]);
            minHeap(nums, minn, N);
        }
    }
    void buildMinHeap(vector<pair<int,int>> &nums, const int N)
    {
        for(int i = ((N-1)-1)>>1; i >= 0; --i)
        {
            minHeap(nums, i, N);
        }
    }
};
