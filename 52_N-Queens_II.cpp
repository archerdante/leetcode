#include <iostream>
#include <vector>
//Follow up for N-Queens problem.
//Now, instead outputting board configurations, return the total number of distinct solutions.
using namespace std;
class Solution {
public:
	int totalNQueens(int n) {
		int count = 0;
		vector<int> vec;
		for(int i = 0; i < n; i++)
		{
			vec.push_back(i);
		}
		permutation(vec, 0, vec.size(), count);
		return count;
	}
private:
	void permutation(vector<int> &vec, const int start, const int N, int &count)
	{
		if(start == N)
		{
			if(isValid(vec,N)) count++;
		}		
		for(int i = start; i < N; i++)
		{
			swap(vec[i], vec[start]);
			permutation(vec, start + 1, N, count);
			swap(vec[i], vec[start]);
		}
	}
	bool isValid(const vector<int> &vec, const int N)
	{
		for(int i = 0; i < N - 1; i++)
		{
			for(int j = i + 1; j < N; j++)
			{
				int a = i - j, b = vec[i] - vec[j];
				if(a == b || a == 0 - b) return false;
			}
		}
		return true;
	}
	void swap(int &a, int &b)
	{
		if(a == b) return;
		a ^=b;
		b ^=a;
		a ^=b;
	}
};
