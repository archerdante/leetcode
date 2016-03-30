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
        vector<int> asc(26,0);
        for(string::iterator it = s.begin(); it != s.end(); it++)
        {
            asc[(*it) - 'a']++;
        }
        for(string::iterator it = t.begin(); it != t.end(); it++)
        {
            int temp = --asc[(*it) - 'a'];
            if(temp < 0) return false;
        }
        for(string::iterator it = s.begin(); it != s.end(); it++)
        {
            if(asc[(*it) - 'a'] > 0) return false;
        }
        return true;
    }
};
