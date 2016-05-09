#include <string>
//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
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
//isMatch("aa", "a*") → true
//isMatch("aa", ".*") → true
//isMatch("ab", ".*") → true
//isMatch("aab", "c*a*b") → true
class Solution {
public:
bool isMatch(string s, string p) {
if(p.empty()) return s.empty();
int ss = s.size(), pp = p.size();
if(pp > 1 && p[1] == '*')
{
if(ss > 0 && (s[0] == p[0] || p[0] == '.'))
{
if(isMatch(s,p.substr(2))) return true;
if(isMatch(s.substr(1), p)) return true;
return false;
}
else
{
return isMatch(s,p.substr(2));
}
}
if(ss > 0 && (s[0] == p[0] || p[0] == '.')) return isMatch(s.substr(1),p.substr(1));
return false;
}
};
