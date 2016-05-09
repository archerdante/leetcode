#include <vector>
#include <string>
using namespace std;
//Write a function to find the longest common prefix string amongst an array of strings.
class Solution {
public:
string longestCommonPrefix(vector<string>& strs) {
if(strs.empty()) return "";
string temp = strs[0];
string ret;
for(int i = 0; i < temp.size(); i++)
{
for(auto &a : strs)
{
if(i >= a.size() || a[i] != temp[i]) return ret;
}
ret.push_back(temp[i]);
}
return ret;
}
};
