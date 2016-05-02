#include <vector>
#include <string>
using namespace std;
//Given two numbers represented as strings, return multiplication of the numbers as a string.
//
//Note:
//The numbers can be arbitrarily large and are non-negative.
//Converting the input string to integer is NOT allowed.
//You should NOT use internal library such as BigInteger.
class Solution {
public:
    string multiply(string num1, string num2) {
        int N = num1.size();
        int M = num2.size();
        vector<int> nums(N + M, 0);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
            {
                nums[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        for(int k = N + M - 1; k >= 1; --k)
        {
            if(nums[k] >= 10)
            {
                nums[k - 1] += nums[k]/10;
                nums[k] %= 10;
            }
        }
        string ret;
        vector<int>::iterator it = nums.begin();
        while(it != nums.end() && *it == 0) ++it;
        if(it == nums.end()) return "0";
        while(it != nums.end())
        {
            ret.push_back('0' + *it++);
        }
        return ret;
    }
};
