#include <iostream>
#include <vector>
//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//For example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
//
//Note:
//You may assume the string contains only lowercase alphabets.
//
//Follow up:
//What if the inputs contain unicode characters? How would you adapt your solution to such case?
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int word[26] = {0};
        for(const auto &a : s)
        {
            word[a - 'a']++;
        }
        for(const auto &b : t)
        {
            if(word[b - 'a']-- == 0) return false;
        }
        return true;
    }
};
