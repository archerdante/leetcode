#include <iostream>
using namespace std;
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree is symmetric:
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//But the following is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively.
//Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> leftdfs;
        stack<TreeNode*> rightdfs;
        leftdfs.push(root);
        rightdfs.push(root);
        while(!leftdfs.empty() && !rightdfs.empty())
        {
            TreeNode *l = leftdfs.top();
            TreeNode *r = rightdfs.top();
            leftdfs.pop();
            rightdfs.pop();
            if(l->val != r->val) return false;
            if((l->left == NULL) && (r->right != NULL)) return false;
            if((l->left != NULL) && (r->right == NULL)) return false;
            if((r->left == NULL) && (l->right != NULL)) return false;
            if((r->left != NULL) && (l->right == NULL)) return false;
            if(l->right) leftdfs.push(l->right);
            if(l->left) leftdfs.push(l->left);
            if(r->left) rightdfs.push(r->left);
            if(r->right) rightdfs.push(r->right);
        }
        if(!leftdfs.empty() || !rightdfs.empty()) return false;
        return true;
    }
};
