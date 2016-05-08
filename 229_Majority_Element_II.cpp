#include <vector>
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
class Solution {
public:
      vector<int> majorityElement(vector<int>& nums) {
        vector<int> majorities;
        int a, b, numa = 0, numb = 0;
        for(auto x: nums) {
			// the order of the loop can not be changed
            if (numa == 0) {
                a = x;
                numa = 1;
            } else if (x == a) {
                numa++;
            } else if (numb == 0) {
                b = x;
                numb = 1;
            } else if (x == b) {
                numb++;
            } else {
                numa--;
                numb--;
            }
        }
        numa = numb = 0;
        for(auto x: nums) {
            if (x == a) {
                numa++;
            } else if (x == b) {
                numb++;
            }
        }
        if (numa > nums.size()/3) {
            majorities.push_back(a);
        }
        if (numb > nums.size()/3) {
            majorities.push_back(b);
        }
        return majorities;
    }
}; 
