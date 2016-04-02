#include <iostream>
#include <vector>
//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//Example:
//Given nums = [-2, 0, 3, -5, 2, -1]
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> -1
//sumRange(0, 5) -> -3
//Note:
//You may assume that the array does not change.
//There are many calls to sumRange function.
class NumArray {
public:
    NumArray(vector<int> &nums) {
        int N = nums.size();
        myNums.resize(N,0);
        int temp = 0;
        for(int i = 0; i < N; i++)
        {
            temp += nums[i];
            myNums[i] = temp;
        }
    }

    int sumRange(int i, int j) {
        int N = myNums.size();
        assert(i >= 0 && i <= j && j < N);
        if(i == 0) return myNums[j];
        else return myNums[j] - myNums[i - 1];
    }
private:
    vector<int> myNums;
};


// Your NumArray object will be instantiated and called as such:
// // NumArray numArray(nums);
// // numArray.sumRange(0, 1);
// // numArray.sumRange(1, 2);
