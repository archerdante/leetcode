#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
//Return:
//
//[
//  ["ate", "eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//Note:
//For the return value, each inner list's elements must follow the lexicographic order.
//All inputs will be in lower-case.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ret;
        unordered_map<int, int> map;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        int i = 0;
        for(auto &a : strs)
        {
            int temp = 1;
            for(auto c : a)
            {
                temp *= primes[c - 'a'];
            }
            if(!map.count(temp))
            {
                map[temp] = i++;
                vector<string> ss;
                ss.push_back(a);
                ret.push_back(ss);
            }
            else
            {
                ret[map[temp]].push_back(a);
            }
        }
        for(auto &a : ret) sort(a.begin(), a.end());
        return ret;
    }
};
