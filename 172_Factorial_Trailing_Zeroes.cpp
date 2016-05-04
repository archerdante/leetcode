//Given an integer n, return the number of trailing zeroes in n!.
//Note: Your solution should be in logarithmic time complexity.
class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        while(n>0) res+=n=n/5;
        return res;
    }
};
