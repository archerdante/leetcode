#include <iostream>
#include <vector>
//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
//The update(i, val) function modifies nums by updating the element at index i to val.
//Example:
//Given nums = [1, 3, 5]
//
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8
//Note:
//The array is only modifiable by the update function.
//You may assume the number of calls to update and sumRange function is distributed evenly.
class NumArray {
public:
    NumArray(vector<int> &nums) {
        N = nums.size();
        arrNum = vector<int>(N,0);
        arrBIT = vector<int>(N + 1, 0);
        for(int i = 0; i < N; i++)
        {
            update(i, nums[i]);
        }
        arrNum = nums;
    }

    void update(int i, int val) {
        int diff = val - arrNum[i];
        arrNum[i] = val;
        int idx = i + 1;
        while(idx <= N)
        {
            arrBIT[idx] += diff;
            idx += idx & (-idx);
        }
    }
    
    int sumFromStart(const int i)
    {
        int temp = 0;
        int idx = i + 1;
        while(idx > 0)
        {
            temp += arrBIT[idx];
            idx -= idx & (-idx);
        }
        return temp;
    }

    int sumRange(int i, int j) {
        return i == 0 ? sumFromStart(j) : sumFromStart(j) - sumFromStart(i - 1);
    }
private:
    vector<int> arrBIT;
    vector<int> arrNum;
    int N;
};


// Your NumArray object will be instantiated and called as such:
// // NumArray numArray(nums);
// // numArray.sumRange(0, 1);
// // numArray.update(1, 10);
// // numArray.sumRange(1, 2);
