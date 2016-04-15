#include <string>
//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//For example:
//    1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB 
class Solution {
public:
    string convertToTitle(int n) {
        if(n < 1) return "";
        string ret;
        for(int i = n - 1; i >= 0; i = i / 26 - 1)
        {
            ret= (char)('A' + (i % 26)) + ret;
        }
        return ret;
    }
};
