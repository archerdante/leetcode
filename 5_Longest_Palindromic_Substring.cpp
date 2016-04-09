#include <iostream>
#include <string>
//Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        if(N <= 1) return s;
        int max = 1;
        int start = 0;
        for(int i = 0; i < N; i++)
        {
            int b = i, e = i;
            while(e < N - 1 && s[e] == s[e + 1]) e++;
            while(b > 0 && e < N - 1 && s[b - 1] == s[e + 1]) 
            {
                b--;
                e++;
            }
            if(e - b + 1 > max) 
            {
                max = e - b + 1;
                start = b;
            }
        }
        return s.substr(start,max);
    }
};
