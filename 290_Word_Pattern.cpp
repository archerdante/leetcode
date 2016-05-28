#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
//Examples:
//pattern = "abba", str = "dog cat cat dog" should return true.
//pattern = "abba", str = "dog cat cat fish" should return false.
//pattern = "aaaa", str = "dog cat cat dog" should return false.
//pattern = "abba", str = "dog dog dog dog" should return false.
//Notes:
//You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vs;
        stringstream os(str);
        string ts;
        unordered_map<char, string> umc;
        unordered_map<string,char> ums;
        while(os >> ts) vs.push_back(ts);
        int N = pattern.size();
        if(N != vs.size()) return false;
        for(int i = 0; i < N; ++i)
        {
            if(umc.count(pattern[i]) ^ ums.count(vs[i])) return false;
            if(!umc.count(pattern[i]))
            {
                umc[pattern[i]] = vs[i];
                ums[vs[i]] = pattern[i];
            }
            else
            {
                if(umc[pattern[i]] != vs[i]) return false;
            }
        }
        return true;
    }
};
