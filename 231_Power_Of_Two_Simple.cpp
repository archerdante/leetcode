#include <iostream>
//Given an integer, write a function to determine if it is a power of two.
//here is a simple way
//if((n & (n - 1)) == 0) return true
//ex. 4 & 3 = 100 & 011 == 0
//!!!but this way is not efficient
using namespace std;
class Solution 
{
	public:
    bool isPowerOfTwo(int n) 
	{
		return (n > 0) && ((n & (n - 1)) == 0);  
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
