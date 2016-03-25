#include <iostream>
//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
//Example 2:
//Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
//This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
using namespace std;
//Definition for an interval.
struct Interval {
int start;
int end;
Interval() : start(0), end(0) {}
Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
private:
    vector<Interval> merge(vector<Interval>& intervals) {
        int N = intervals.size();
        if(N <= 1) return intervals;
        insertSort(intervals, N);
        vector<Interval> ret;
        Interval temp(intervals[0].start, intervals[0].end);
        int i = 1;
        while(i < N)
        {
            if(temp.end >= intervals[i].start && temp.end < intervals[i].end)
            {
                temp.end = intervals[i].end;
                i++;
            }
            else if(temp.end < intervals[i].start)
            {
                ret.push_back(temp);
                temp = intervals[i++];
            }
            else
            {
                i++;
            }
        }
        ret.push_back(temp);
        return ret;
    }
    void insertSort(vector<Interval> &intervals, const int N)
    {
        int k = N - 1;
        for(int j = N - 2; j >= 0; j--)
        {
            if(intervals[j].start > intervals[k].start) 
            {
                swapInterval(intervals[j],intervals[k]);
                k = j;
            }
            else
            {
                break;
            }
        }
    }
    void swapInterval(Interval &a, Interval &b)
    {
        swap(a.start, b.start);
        swap(a.end, b.end);
    }
    void swap(int &a, int &b)
    {
        if(a == b) return;
        a ^= b;
        b ^= a;
        a ^= b;
    }
};

