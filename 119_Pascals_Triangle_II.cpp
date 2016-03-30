#include <iostream>
#include <vector>
//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return [1,3,3,1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space?
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1,1);
        if(rowIndex <= 1) return ret;
        for(int i = 2; i <= rowIndex; i++)
        {
            int temp_1 = 1;
            for(int j = 1; j < i; j++)
            {
                int temp_2 = ret[j];
                ret[j] = ret[j] + temp_1;
                temp_1 = temp_2;
            }
        }
        return ret;
    }
};
