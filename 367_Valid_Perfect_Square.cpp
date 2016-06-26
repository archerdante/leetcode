//Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
//Note: Do not use any built-in library function such as sqrt.
//
//Example 1:
//
//Input: 16
//Returns: True
//Example 2:
//
//Input: 14
//Returns: False
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 1) return false;
        int l = 1, h = (num >> 1) + 1, m = 0;
        while(l <= h)
        {
            m = l + ((h - l) >> 1);
            if(m == (num / m))
            {
                if(m*m == num) return true;
                else return false;
            }
            else if(m < (num / m)) l = m + 1;
            else h = m - 1;
        }
        return false;
    }
};
