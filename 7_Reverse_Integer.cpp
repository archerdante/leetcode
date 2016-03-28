#include <iostream>
#include <stream>
//Reverse digits of an integer.
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//Have you thought about this?
//Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
//If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
//For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
using namespace std;
class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        reverseString(s);
        return myAtoi(s);
    }
private:
    void reverseString(string &s)
    {
        int i = 0, j = s.size() - 1;
        if(s[0] == '-') i++;
        while(i < j) swap(s[i++], s[j--]);
    }
    int myAtoi(string &s)
    {
        if(s == "") return 0;
        int i = 0;
        int flag = 1;
        int N = s.size();
        if(s[0] == '-') 
        {
            flag = -1;
            i++;
        }
        int ret = 0;
        while(i < N)
        {
            int k = s[i] - '0';
            if(k >= 0 && k <= 9)
            {
                if(ret > INT_MAX /10 || (ret == INT_MAX / 10 && k > INT_MAX % 10))
                {
                    return 0;
                }
                ret = ret*10 + k;
            }
            i++;
        }
        return ret*flag;
    }
};
