#include <iostream>
//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].
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
    vector<Interval> merge(vector<Interval>& intervals) {
        int N = intervals.size();
        if(N <= 1) return intervals;
        quickSort(intervals, 0, N - 1);
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
private:
    void quickSort(vector<Interval> &intervals, const int b, const int e)
    {
        if(b >= e) return;
        int i = b, j = e, x = intervals[b + rand()%(e - b + 1)].start;
        do
        {
            while(intervals[i].start < x) i++;
            while(intervals[j].start > x) j--;
            if(i <= j) swapInterval(intervals[i++], intervals[j--]);
        } while (i < j);
        if(i < e) quickSort(intervals, i, e);
        if(j > b) quickSort(intervals, b, j);
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
