//Divide two integers without using multiplication, division and mod operator.
//If it is overflow, return MAX_INT.
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        long long dv = llabs(dividend);
        long long ds = llabs(divisor);
        int ret = 0;
        while(dv >= ds)
        {
            long long temp = ds;
            long long count = 1;
            while(dv >= (temp << 1))
            {
                temp <<= 1;
                count <<= 1;
            }
            ret += count;
            dv -= temp;
        }
        return sign == 1 ? ret : -ret;
    }
};
