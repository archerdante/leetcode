#include <iostream>
#include <vector>
//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N = gas.size();
		int start = 0;
		int ret = -1;
		while(start < N)
		{
			int p = canCompleteFromOneStation(gas, cost, start, N, ret);
			if(ret != -1) return ret;
			if(p <= start) return -1;
			start = p;
		}
		return ret;
	}
private:
	int canCompleteFromOneStation(vector<int>& gas, vector<int>& cost, const int start, const int N,int &ret)
	{
		int i = start;
		int gasValue = 0;
		do
		{
			gasValue += gas[i];
			if(gasValue >= cost[i])
			{
				gasValue -= cost[i];
				i++;
				if(i == N) i = 0;
			}
			else return i + 1;
		} while(i != start);
		ret = start;
		return start;
	}
};
