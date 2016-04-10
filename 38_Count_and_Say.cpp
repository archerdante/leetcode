#include <iostream>
#include <string>
#include <vector>
//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        vector<int> last = vector<int>(1,1);
        for(int i = 2; i <= n; i++)
        {
            vector<int> temp;
            int N = last.size();
            for(int j = 0; j < N;)
            {
                int c = 1;
                while(j < N - 1 && last[j + 1] == last[j]) 
                {
                    c++;
                    j++;
                }
                temp.push_back(c);
                temp.push_back(last[j++]);
            }
            last = temp;
        }
        string ret;
        for(vector<int>::iterator it = last.begin(); it != last.end(); it++)
        {
            ret.push_back((char)('0' + *it));
        }
        return ret;
    }
};
