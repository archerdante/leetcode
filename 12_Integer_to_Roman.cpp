#include <iostream>
#include <string>
//Given an integer, convert it to a roman numeral.
//Input is guaranteed to be within the range from 1 to 3999.
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        const string temp[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        const int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string ret = "";
        int myNum  = num;
        for(int i = 12; i >= 0; i--)
        {
            while(myNum >= nums[i])
            {
                ret += temp[i];
                myNum -= nums[i];
            }
        }
        return ret;
    }
};
