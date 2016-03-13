#include <iostream>
#include <math.h>
//Given an integer, write a function to determine if it is a power of three.
//
//Follow up:
//Could you do it without using any loop / recursion?
//
//Credits:
//Special thanks to @dietpepsi for adding this problem and creating all test cases.
//
//Subscribe to see which companies asked this question
class Solution {
public:
    bool isPowerOfThree(int n) {
        double res = log(n)/log(3);  //换底公式求指数
        return (abs(res - rint(res)) < 0.0000000001);  //主要要用rint
    }
};
