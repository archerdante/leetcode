#include <iostream>
//Implement pow(x, n).
using namespace std;
class Solution 
{
	public:
    double myPow(double x, int n) 
	{
		if( !(x > 0.000000001 || x < - 0.0000000001)) return 0.0; //x = 0
		if(n == 0) return 1.0;
		if(n < 0)
			return 1/pow(x,-n);
		else 
			return pow(x,n);
    }
	private:
	double pow(double x, unsigned int n)
	{
		if(n == 1) return x;
		double a = pow(x,n/2);
		if((n & 1) == 1) //n为奇数
			return a*a*x;
		else
			return a*a;
	}
};

int main()
{
	Solution s;
	cout << s.myPow(10,2) << endl;
	cout << s.myPow(0,2) << endl;
	cout << s.myPow(10,0) << endl;
	cout << s.myPow(1.1,3) << endl;
	cout << s.myPow(10,-3) << endl;
	cout << s.myPow(-1.1,-3) << endl;
	return 0;
}
