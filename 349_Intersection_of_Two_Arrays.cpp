#include <vector>
//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
//Note:
//Each element in the result must be unique.
//The result can be in any order.
class Solution {
public:
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
if(nums1.size() > nums2.size()) intersection(nums2, nums1);
set<int> hash;
vector<int> ret;
for(auto &a : nums1)
{
hash.insert(a);
}
for(auto &b : nums2)
{
if(hash.count(b))
{
ret.push_back(b);
hash.erase(b);
}
}
return ret;
}
};
