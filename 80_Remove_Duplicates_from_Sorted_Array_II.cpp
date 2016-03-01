#include <iostream>
#include <vector>
/**
*Follow up for "Remove Duplicates":
*What if duplicates are allowed at most twice?
*For example,
*Given sorted array nums = [1,1,1,2,2,3],
*Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 It doesn't matter what you leave beyond the new length.
*/
using namespace std;
class Solution 
{     
    public:
    int removeDuplicates(vector<int>& nums)
    {
		int n = nums.size();
        if(n <= 2) return n;
        int p = 1, q = 1, iCount = 1;
        while(q < n)
        {   
            if(nums[q] == nums[q - 1]) 
            {   
                iCount++;
            }   
            else 
            {   
                iCount = 1;
            }   
            if(iCount <= 2) {nums[p++] = nums[q++];}
            else q++;
        }   
        return p;
    }
};
int main()
{
	int a,n;
	vector<int> nums;
	cout << "please input nums" << endl;
	while(cin >> a)
	{
		nums.push_back(a);			
	}
	Solution s;
	n = s.removeDuplicates(nums);	
	cout << "length:" << n << endl;
	for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)	
	{	
		cout << *it << endl;
	}
}
