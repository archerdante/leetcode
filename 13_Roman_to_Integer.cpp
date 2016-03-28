#include <iostream>
#include <string>
//Given a roman numeral, convert it to an integer.
//Input is guaranteed to be within the range from 1 to 3999.
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int N = s.size();
        if(N == 0) return 0;
        int ret = getRomantoInt(s[0]);
        int last = getRomantoInt(s[0]);
        for(int i = 1; i < N; i++)
        {
            int temp = getRomantoInt(s[i]);
            ret += temp;
            if(temp > last) ret -= 2 * last;
            last = temp;
        }
        return ret;
    }
private:
    int getRomantoInt(const char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
        return 0;
    }
};
