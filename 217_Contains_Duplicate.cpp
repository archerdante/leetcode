#include <iostream>
#include <vector>
//Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            if(s.count(*it)) return true;
            else s.insert(*it);
        }
        return false;
    }
};
