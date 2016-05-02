#include <iostream>
//Given two binary strings, return their sum (also a binary string).
//For example,
//a = "11"
//b = "1"
//Return "100".
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
       	string big, small;
        const int cc = 2;
        if(a.size() > b.size())
        {
            big = a;
            small = b;
        }
        else
        {
            big = b;
            small = a;
        }
        int iC = 0;
        int i = big.size() - 1;
        int j = small.size() - 1;
        while(i >= 0)
        {
            int t = (big[i] - '0') + (j>=0?small[j] - '0':0) + iC;
            iC = t/cc;
            big[i] = (t%cc) + '0';
            i--;
            j--;
        }
        if(iC > 0) big.insert(big.begin(),'0' + iC);
        return big; 
    }
};
