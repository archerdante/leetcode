#include <string>
using namespace std;
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty? This is a good question to ask during an interview.
//
//For the purpose of this problem, we define empty string as valid palindrome.
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        string::iterator its = s.begin(), ite = s.end() - 1;
        while(its < ite)
        {
            while(its < ite && !(((*its) - 'A' >= 0 && (*its) - 'A' < 26) || ((*its) - 'a' >= 0 && (*its) - 'a' < 26) || (*its - '0' >= 0 && *its - '0' <= 9))) ++its;
            while(its < ite && !(((*ite) - 'A' >= 0 && (*ite) - 'A' < 26) || ((*ite) - 'a' >= 0 && (*ite) - 'a' < 26) || (*ite - '0' >= 0 && *ite - '0' <= 9))) --ite;
            if(its < ite)
            {
                char tempS = (*its) - 'A' >= 0 && (*its) - 'A' < 26 ? 'a' + ((*its) - 'A') : (*its); 
                char tempE = (*ite) - 'A' >= 0 && (*ite) - 'A' < 26 ? 'a' + ((*ite) - 'A') : (*ite); 
                if(tempS != tempE) return false;
                ++its;
                --ite;
            }
            else break;
        }
        return true;
    }
};
