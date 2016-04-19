#include <string>
using namespace std;
//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non-empty and contain only digits and the . character.
//The . character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//Here is an example of version numbers ordering:
//
//0.1 < 1.1 < 1.2 < 13.37
class Solution {
public:
    int compareVersion(string version1, string version2) {
        string::iterator it_1 = version1.begin();
        string::iterator it_2 = version2.begin();
        int num1 = 0, num2 = 0;
        while(it_1 != version1.end() && it_2 != version2.end())
        {
            if((*it_1) == '.')it_1++;
            if((*it_2) == '.')it_2++;
            while((*it_1) != '.' && it_1 != version1.end())
            {
                num1 += num1 * 10 + (int)((*it_1) - '0');
                it_1++;
            }
            while((*it_2) != '.' && it_2 != version2.end())
            {
                num2 += num2 * 10 + (int)((*it_2) - '0');
                it_2++;
            }
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            num1 = 0;
            num2 = 0;
        }
        while(it_1 != version1.end())
        {
            if((*it_1) != '.' && (*it_1) != '0') return 1;
            it_1++;
        }
        while(it_2 != version2.end())
        {
            if((*it_2) != '.' && (*it_2) != '0') return -1;
            it_2++;
        }
        return 0;
    }
};
