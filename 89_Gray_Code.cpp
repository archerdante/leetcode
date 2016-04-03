#include <iostream>
#include <vector>
//The gray code is a binary numeral system where two successive values differ in only one bit.
//Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
//For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//00 - 0
//01 - 1
//11 - 3
//10 - 2
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        int N = 1 << n;
        vector<int> grayCode;
        grayCode.resize(N);
        for(int i = 0; i < N; i++)
        {
            grayCode[i] = i ^ (i >> 1);
        }
        return grayCode;
    }
};
