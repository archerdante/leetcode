#include <iosstream>
//Determine whether an integer is a palindrome. Do this without extra space.
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int reverse = 0;
        int orgX = x;
        while(x > 0)
        {
            reverse = reverse * 10 + (x % 10);
            x = x / 10;
        }
        return reverse == orgX;
    }
};
