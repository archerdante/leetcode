#include <iostream>
#include <string>
//A message containing letters from A-Z is being encoded to numbers using the following mapping:
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given an encoded message containing digits, determine the total number of ways to decode it.
//For example,
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//The number of ways decoding "12" is 2.
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        if(N == 0) return 0;
        if(N == 1) return s[0] == '0' ? 0 : 1;
        int lastlastNum = 1;
        int lastNum = 1;
        int lastChar = s[0] - '0';
        if(lastChar == 0) return 0;
        int i = 1;
        while(i < N)
        {
            int nowChar = s[i] - '0';
            if(nowChar == 0)
            {
                if(!(lastChar == 1 || lastChar == 2)) return 0;
                lastNum = lastlastNum;
                lastChar = s[i + 1] - '0';
                if(lastChar == 0) return 0;
                i = i + 2;
            }
            else if(lastChar * 10 + nowChar <= 26)
            {
                int temp = lastNum;
                lastNum = lastNum + lastlastNum;
                lastlastNum = temp;
                lastChar = nowChar;
                i++;
            }
            else
            {
                lastlastNum = lastNum;
                lastChar = nowChar;
                i++;
            }
        }
        return lastNum;
    }
};
