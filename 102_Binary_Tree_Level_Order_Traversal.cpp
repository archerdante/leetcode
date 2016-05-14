#include <vector>
#include <queue>
using namespace std;
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example:
//Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
// /  \
//15   7
//return its level order traversal as:
//[
//	[3],
//  [9,20],
//  [15,7]
//]
//Definition for a binary tree node.
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if(root == nullptr) return ret;
        int now = 1, next = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left) q.push(node->left), ++next;
            if(node->right) q.push(node->right), ++next;
            if(now == 1)
            {
                ret.push_back(temp);
                temp.clear();
                now = next;
                next = 0;
            }
            else
            {
                --now;
            }
        }
        return ret;
    }
};
