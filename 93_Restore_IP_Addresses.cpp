#include <string>
using namespace std;
//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//For example:
//Given "25525511135",
//
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int N = s.size();
        vector<string> ret;
        for(int a = 1; a <= 3; ++a)
        for(int b = 1; b <= 3; ++b)
        for(int c = 1; c <= 3; ++c)
        {
            int d = N - (a + b + c);
            
            if(d <= 3 && d > 0)
            {
                int A = stoi(s.substr(0,a));
                int B = stoi(s.substr(a,b));
                int C = stoi(s.substr(a+b,c));
                int D = stoi(s.substr(a+b+c,d));
                if(A <= 255 && B <= 255 && C <= 255 && D <= 255)
                {
                    string temp = to_string(A) + "." + to_string(B) + "." +  to_string(C) + "." + to_string(D);
                    if(temp.size() == s.size() + 3) ret.push_back(temp);
                }
            }
        }
        return ret;
    }
};
