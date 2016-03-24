#include <iostream>
#include <vector>
//The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
//There exist two distinct solutions to the 4-queens puzzle:
//
//[
// [".Q..",  // Solution 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // Solution 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> map;
		vector<int> vec;
		for(int i = 0; i < n; i++)
		{
			vec.push_back(i);
		}
		permutation(vec, 0, vec.size(), map);
		return map;
	}
private:
	void permutation(vector<int> &vec, const int start, const int N, vector<vector<string>> &map)
	{
		if(start == N)
		{
			if(isValid(vec,N)) getMap(map,vec,N);
		}
		for(int i = start; i < N; i++)
		{
			swap(vec[i], vec[start]);
			permutation(vec, start + 1, N, map);
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
	void getMap(vector<vector<string>> &map,const vector<int> &vec, const int N)
	{
		vector<string> v;
		for(int i = 0; i < N; i++)
		{
			string row = "";
			for(int j = 0; j < N; j++)
			{
				string temp = (j == vec[i]) ? "Q" : ".";
				row += temp;
			}
			v.push_back(row);
		}
		map.push_back(v);
	}
};
