#include <stack>
#include <string>
using namespace std;
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples:
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
//Note: Do not use the eval built-in library function.
//
//Subscribe to see which companies asked this question
class Solution {
public:
    int calculate(string s) {
        stack<int> nums,ops;
        int num = 0;
        int sign = 1;
        int ret = 0;
        for(auto &c : s)
        {
            if(isdigit(c))
            {
                num = num*10 + (c - '0');
            }
            else
            {
                ret += sign * num;
                num = 0;
                if(c == '+') sign = 1;
                else if(c == '-') sign = -1;
                else if(c == ')')
                {
                    ret = ops.top()*ret + nums.top();
                    ops.pop();
                    nums.pop();
                }
                else if(c == '(')
                {
                    nums.push(ret);
                    ops.push(sign);
                    ret = 0;
                    sign = 1;
                }
            }
        }
        ret += num * sign;
        return ret;
    }
};
