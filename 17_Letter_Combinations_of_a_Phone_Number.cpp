//Given a digit string, return all possible letter combinations that the number could represent.
//A mapping of digit to letters (just like on the telephone buttons) is given below.
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
class Solution {
public:
vector<string> letterCombinations(string digits) {
vector<string> ret;
if(digits.empty()) return ret;
ret.push_back("");
vector<string> phone = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
for(auto &s : digits)
{
vector<string> temp;
for(auto &a : ret)
{
for(auto &b : phone[s - '2'])
{
string c = a;
c.push_back(b);
temp.push_back(c);
}
}
ret = temp;
}
return ret;
}
};
