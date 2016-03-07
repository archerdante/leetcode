#include <iostream>
/*Implement atoi to convert a string to an integer.
*
*Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
*
*Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/
using namespace std;
class Solution 
{
	public:
    int myAtoi(string str) 
	{
		if(str == "") return 0;
        const int n = str.size();    
        int num = 0;
        int flag = 1;
        int i = 0;
        while(str[i] == ' ')
            i++;
        if(str[i] == '+') i++;
        else if(str[i] == '-')
        {   
            flag = -1;  
            i++;
        }   
        for(; i < n; i++)
        {   
            if(str[i] >= '0' && str[i] <= '9')
            {   
                if(num > INT_MAX / 10 || ((num == INT_MAX / 10) && (str[i] - '0') > INT_MAX % 10))  
                {   
                    return flag > 0 ? INT_MAX : INT_MIN;
                }   
                num = num * 10 + (str[i] - '0');
            }
            else
            break;
        }   
        return num * flag;
    }
};
