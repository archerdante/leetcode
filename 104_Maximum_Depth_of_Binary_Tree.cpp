#include <iostream>
//Given a binary tree, find its maximum depth.
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 0;
        int max = 0;
        dfs(root,depth,max);
        return max;
    }
private:
    void dfs(TreeNode *node, int &depth, int &max)
    {
        if(node == NULL)
        {
            return;
        }
        depth++;
        max = depth>max?depth:max;
        dfs(node->left, depth, max);
        dfs(node->right,depth, max);
        depth--;
    }
};
