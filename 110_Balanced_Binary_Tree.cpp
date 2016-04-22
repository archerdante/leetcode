#include <stack>
//Given a binary tree, determine if it is height-balanced.
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> s_1;
        stack<TreeNode*> s_2;
        s_1.push(root);
        while(!s_1.empty())
        {
            TreeNode *node = s_1.top();
            s_1.pop();
            if(node->right != NULL) s_1.push(node->right);
            if(node->left != NULL) s_1.push(node->left);
            s_2.push(node);
        }
        while(!s_2.empty())
        {
            TreeNode *node = s_2.top();
            s_2.pop();
            int lH = getHeight(node->left);
            int rH = getHeight(node->right);
            if(lH - rH < -1 || lH - rH > 1) return false;
            node->val = (lH > rH ? lH : rH) + 1;
        }
        return true;
    }
private:
    int getHeight(const TreeNode* node)
    {
        if(node == NULL) return 0;
        else return node->val;
    }
};
