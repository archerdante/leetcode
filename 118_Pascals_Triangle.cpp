#include <iostream>
#include <vector>
/**
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */
using namespace std;
class Solution
{
	public:
	vector<vector<int> > generate(int numRows)
	{
		vector<vector<int> > result;
		for(int i = 0; i < numRows; i++)
		{
			int b = 1,e = i;
			vector<int> temp(i+1,1);
			for(;b < e;b++)
			{
				temp[b] = result[i - 1][b - 1] + result[i - 1][b];
			}
			result.push_back(temp);
		}
		return result;
	}
};

int main()
{
	int n;
	cout << "please input num" << endl;
	cin >> n;
	Solution s;
	vector<vector<int> > result = s.generate(n);
	for(vector<vector<int> >::iterator itt = result.begin();itt != result.end();itt++)
	{
		for(vector<int>::iterator it = (*itt).begin();it != (*itt).end();it++)
		{
			cout << *it << ' ';
		}
		cout << endl;
	}
}
