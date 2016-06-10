#include <vector>
using namespace std;
//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.empty()) return 0;
        int max = 0, N = points.size();
        for(int i = 0; i < N; ++i)
        {
            unordered_map<double, int> um;
            Point p = points[i];
            int sameP = 1, temp = 0;
            for(int j = i + 1; j < N; ++j)
            {
                Point tp = points[j];
                if(p.x == tp.x)
                {
                    if(p.y == tp.y)
                    {
                        ++sameP;
                    }
                    else
                    {
                        ++um[INT_MAX];
                    }
                }
                else
                {
                    um[double(tp.y-p.y)/double(tp.x-p.x)]++;
                }
            }
            for(auto &a : um)
            {
                if(a.second > temp) temp = a.second;
            }
            temp += sameP;
            if(temp > max) max = temp;
        }
        return max;
    }
};
