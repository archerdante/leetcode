#include <iostream>
#include <vector>
#include <map>
//Given two strings s and t, determine if they are isomorphic.
//Two strings are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//For example,
//Given "egg", "add", return true.
//Given "foo", "bar", return false.
//Given "paper", "title", return true.
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> vs = stdString(s);
        vector<int> vt = stdString(t);
        if(vs.size() != vt.size()) return false;
        vector<int>::iterator its = vs.begin();
        vector<int>::iterator itt = vt.begin();
        for(;its != vs.end() && itt != vt.end();its++,itt++)
        {
            if((*its) != (*itt)) return false;
        }
        return true;
    }
private:
    vector<int> stdString(string s)
    {
        unordered_map <char, int> m;
        vector<int> v;
        string::iterator it = s.begin();
        int i = 0;
        for(; it != s.end(); it++)
        {
            if(m.count(*it) == 0) m[*it] = i++;
            v.push_back(m[*it]);
        }
        return v;
    }
};

