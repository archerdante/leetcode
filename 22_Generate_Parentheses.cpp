#include <vector>
using namespace std;
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//"((()))", "(()())", "(())()", "()(())", "()()()"
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n < 1) return ret;
        generateCore(ret, "",n,n);
        return ret;
    }
private:
    void generateCore(vector<string> &ret, string temp, int m, int n)
    {
        if(m == 0 && n == 0)
        {
            ret.push_back(temp);
        }
        if(m > 0)
        {
            generateCore(ret, temp+"(",m-1,n);
        }
        if(n > m)
        {
            generateCore(ret,temp+")",m,n-1);
        }
    }
};
