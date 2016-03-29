#include <iostream>
#include <string>
#include <vector>
//Given a list of non negative integers, arrange them such that they form the largest number.
//For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//Note: The result may be very large, so you need to return a string instead of an integer.
using namespace std;
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		int N = nums.size();
		string ret = "";
		myQuickSort(nums, 0, N - 1);
		int i = N - 1;
		while(i > 0 && nums[i] == 0) i--;
		for (; i >= 0; i--)
		{
		    ret += to_string(nums[i]);
		}
		return ret;
	}
private:
	int myNumcmp(const int a, const int b)
	{
		string s1 = to_string(a);
		string s2 = to_string(b);
		int ret = strcmp((s1 + s2).c_str(), (s2 + s1).c_str());
		return ret;
	}
	void myQuickSort(vector<int>& nums, const int b, const int e)
	{
		if (b >= e) return;
		int i = b, j = e, x = nums[b + rand() % (e - b + 1)];
		do
		{
			while (myNumcmp(nums[i], x) < 0) i++;
			while (myNumcmp(nums[j], x) > 0) j--;
			if (i <= j) swap(nums[i++], nums[j--]);
		} while (i < j);
		if (j > b) myQuickSort(nums, b, j);
		if (i < e) myQuickSort(nums, i, e);
	}
	void swap(int &a, int &b)
	{
	    if(a == b) return;
	    a ^= b;
	    b ^= a;
	    a ^= b;
	}
};
