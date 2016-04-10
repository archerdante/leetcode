#include <iostream>
#include <string>
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int N = s.size();
        if(numRows <= 1) return s;
        int distance = (numRows-1) * 2;
        string ret;
        for(int i = 0; i < numRows; i++)
        {
            int t = 0;
            for(int j = i; j < N;)
            {
                ret.push_back(s[j]);
                if(i == 0 || i == numRows - 1)
                {
                    j += distance;
                }
                else
                {
                    j = (++t) * distance - j;
                }
            }
        }
        return ret;
    }
};
