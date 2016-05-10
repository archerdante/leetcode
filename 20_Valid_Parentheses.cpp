#include <string>
using namespace std;
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto a : s)
        {
            if(a == '(' || a == '[' || a == '{') st.push(a);
            else
            {
                switch(a)
                {
                    case ')':
                        if(st.empty() || st.top() != '(') return false;
                        st.pop();
                        break;
                    case ']':
                        if(st.empty() || st.top() != '[') return false;
                        st.pop();
                        break;
                    case '}':
                        if(st.empty() || st.top() != '{') return false;
                        st.pop();
                        break;
                }
            }
        }
        return st.empty();
    }
};
