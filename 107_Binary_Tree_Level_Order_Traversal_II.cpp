#include <vector>
using namespace std;
//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//For example:
//Given binary tree {3,9,20,#,#,15,7},
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//return its bottom-up level order traversal as:
//
//[
//  [15,7],
//  [9,20],
//  [3]
//]
/**
 * * Definition for a binary tree node.
 * * struct TreeNode {
 * * int val;
 * * TreeNode *left;
 * * TreeNode *right;
 * * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * * };
 * */
class Solution {
public:
vector<vector<int>> levelOrderBottom(TreeNode* root) {
vector<vector<int> > ret;
if(root == nullptr) return ret;
queue<TreeNode*> q;
q.push(root);
vector<int> temp;
int now = 1, next = 0;
while(!q.empty())
{
TreeNode* node = q.front();
q.pop();
--now;
temp.push_back(node->val);
if(node->left != nullptr) q.push(node->left), ++next;
if(node->right != nullptr) q.push(node->right), ++next;
if(now == 0)
{
now = next;
next = 0;
ret.push_back(temp);
temp.clear();
}
}
int b = 0, e = ret.size() - 1;
while(b < e)
{
swap(ret[b++],ret[e--]);
}
return ret;
}
};
