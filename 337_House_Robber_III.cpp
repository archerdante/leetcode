#include <iostream>
using namespace std;
//The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//
//Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//Example 1:
//     3
//    / \
//   2   3
//    \   \ 
//     3   1
//Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//Example 2:
//     3
//    / \
//   4   5
//  / \   \ 
// 1   3   1
//Maximum amount of money the thief can rob = 4 + 5 = 9.
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        int now = 0, last = 0;
        dfs(root,now,last);
        return now;
    }
private:
    void dfs(TreeNode* node, int &now, int &last)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            now += node->val;
            last += 0;
            return;
        }
        int now_t = 0, last_t = 0;
        if(node->left) dfs(node->left, now_t , last_t);
        if(node->right) dfs(node->right, now_t, last_t);
        if(now_t > last_t + node->val)
        {
            now += now_t;
            last += now_t;
        }
        else
        {
            now += last_t + node->val;
            last += now_t;
        }
    }
};
