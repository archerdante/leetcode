#include <iostream>
//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int um[256];
        memset(um, -1, sizeof(um));
        const int n = s.length();
        int p = -1;
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            if(um[s[i]] > p) //如果有记录，则把游标移动到之前记录的位置
            {
                int q = um[s[i]];
                p = q > p ? q : p;  //考虑"tmiamt"的情况,t再次出现，但是之前的t的位置比现在p的位置要靠前，不移动（p不会向前移动，只会向后移动）
            }
            int temp = i - p;
            max = temp > max ? temp : max; 
            um[s[i]] = i;
        }
        return max;
    }
};
