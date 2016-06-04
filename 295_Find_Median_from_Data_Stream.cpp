#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
//Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//
//Examples: 
//[2,3,4] , the median is 3
//
//[2,3], the median is (2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations:
//
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.
//For example:
//
//add(1)
//add(2)
//findMedian() -> 1.5
//add(3) 
//findMedian() -> 2
class MedianFinder {
public:

    void addNum(int num) {
        if(((heap_min.size() + heap_max.size()) & 1) == 0)
        {
            if(heap_max.size() > 0 && heap_max.front() > num)
            {
                heap_max.push_back(num);
                push_heap(heap_max.begin(), heap_max.end(), less<int>());
                num = heap_max.front();
                pop_heap(heap_max.begin(), heap_max.end(), less<int>());
                heap_max.pop_back();
            }
            heap_min.push_back(num);
            push_heap(heap_min.begin(), heap_min.end(), greater<int>());
        }
        else
        {
            if(heap_min.size() > 0 && heap_min.front() < num)
            {
                heap_min.push_back(num);
                push_heap(heap_min.begin(), heap_min.end(), greater<int>());
                num = heap_min.front();
                pop_heap(heap_min.begin(), heap_min.end(), greater<int>());
                heap_min.pop_back();
            }
            heap_max.push_back(num);
            push_heap(heap_max.begin(), heap_max.end(), less<int>());
        }
    }

    double findMedian() {
        int size = heap_min.size() + heap_max.size();
        if(size == 0) return 0.0;
        if((size & 1) == 0) return ((double)heap_min.front() + (double)heap_max.front()) / 2;
        else return heap_min.front();
    }
private:
    vector<int> heap_min;
    vector<int> heap_max;
};
int main()
{
	return 0;
}
