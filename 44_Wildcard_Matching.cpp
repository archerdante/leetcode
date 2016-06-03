#include <string>
using namespace std;
//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false
class Solution {
public:
    bool isMatch(string s, string p) {
        string::iterator its = s.begin(), itp = p.begin(), itstar = p.end(), itrecord = s.end();
        while(its != s.end())
        {
            if(itp != p.end() && (*its == *itp || *itp == '?')) 
            {   
                ++its;++itp;continue;
            }
            if(itp != p.end() && (*itp == '*')) 
            {
                itstar = itp++;itrecord = its;continue;
            }
            if(itstar != p.end()) 
            {
                its = ++itrecord;itp = itstar+1;continue;
            }
            return false;
        }
        while(itp != p.end() && (*itp) == '*') ++itp;
        return (its == s.end() && itp == p.end());
    }
};
