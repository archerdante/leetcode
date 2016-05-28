#include <string>
using namespace std;
//Write a function that takes a string as input and reverse only the vowels of a string.
//
//Example 1:
//Given s = "hello", return "holle".
//
//Example 2:
//Given s = "leetcode", return "leotcede".
class Solution {
public:
    string reverseVowels(string s) {
        set<char> hash;
        vector<char> vs = {'a','e','i','o','u','A','E','I','O','U'};
        for(auto a:vs) 
        {
            hash.insert(a);
        }
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            while(i < j && !hash.count(s[i])) i++;
            while(i < j && !hash.count(s[j])) j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
