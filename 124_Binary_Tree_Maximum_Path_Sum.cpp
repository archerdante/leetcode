#include <iostream>
using namespace std;
//Given a binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
//
//For example:
//Given the below binary tree,
//
//       1
//      / \
//     2   3
//Return 6.
//Definition for a binary tree node.
struct TreeNode {
	 int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        postorder(root, maxsum);
        return maxsum;
    }
private:
    int postorder(const TreeNode *root, int &maxsum)
    {
        if(root == nullptr) return 0;
        int l = postorder(root->left, maxsum);
        int r = postorder(root->right, maxsum);
        int sum = root->val;
        if(l > 0) sum += l;
        if(r > 0) sum += r;
        maxsum = sum > maxsum ? sum : maxsum;
        return max(l,r) > 0 ? max(l,r) + root->val : root->val;
    }
};
