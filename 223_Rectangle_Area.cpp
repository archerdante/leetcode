#include <Math>
//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//Rectangle Area
//Assume that the total area is never beyond the maximum possible value of int.
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ret = (C - A) * (D - B) + (G - E) * (H - F);
        if(C <= E|| G <= A|| D <= F|| H <= B) return ret;
        int dX = (C < G ? C : G) - (A > E ? A : E);
        int dY = (D < H ? D : H) - (B > F ? B : F);
        return ret - dX * dY;
    }
};
