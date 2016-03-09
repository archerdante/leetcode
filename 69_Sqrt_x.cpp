#include <iostream>
#include <limits.h>
//Implement int sqrt(int x).
//Compute and return the square root of x.
using namespace std;
class Solution 
{
	public:
    int mySqrt(int x) 
	{
 		if (x <= 1) return x;       
		int h = (x / 2) + 1, l = 1, m = 0;  //开根号的范围 1~x/2+1
		while(h - l > 1)
		{
			m = l + (h - l) / 2;  //用除法判断不会越界
			if(m == x / m) return m;
			else if(m > x / m) h = m;
			else l = m;
		}
		if(l <= x / l) return l;
		else return h;
    }
};

int main()
{
	Solution s;
	int a[] = {-1,0,1,2,3,4,10,200,9,INT_MAX};
	for(int i = 0; i < end(a) - begin(a); i++)
	{
		cout << a[i] << " sqrt:" << s.mySqrt(a[i]) << endl;
	}
	return 0;
}
