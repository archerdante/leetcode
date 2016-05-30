#include <vector>
using namespace std;
//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int min = INT_MAX;
        dfs(root, min, 1);
        return min;
    }
private:
    void dfs(TreeNode *node, int &min, int depth)
    {
        if(depth >= min) return;
        if(!node->left && !node->right) min = depth;
        if(node->left) dfs(node->left, min, depth + 1);
        if(node->right) dfs(node->right, min, depth + 1);
    }
};
