#include <iostream>
//Given an integer, write a function to determine if it is a power of two.
using namespace std;
class Solution 
{
	public:
    bool isPowerOfTwo(int n) 
	{
 		if(n < 0) return false;
		int iCount = 0;
		while(n != 0)     
		{
			if(n & 1) iCount++;
			n = n >> 1;
		}
		return (iCount == 1 ? true : false);
    }
};

int main()
{
	cout << "please input n" << endl;
	int n;
	cin >> n;
	Solution s;
	cout << s.isPowerOfTwo(n) << endl;
	return 0;
}
