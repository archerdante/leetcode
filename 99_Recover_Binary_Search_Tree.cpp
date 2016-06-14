#include <vector>
//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
//Subscribe to see which companies asked this question
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }

private:
    TreeNode temp = TreeNode(INT_MIN); 
    TreeNode *pre = &temp;
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    void inorder(TreeNode* node)
    {
        if(node == nullptr) return;
        inorder(node->left);
        if(first == nullptr && pre->val >= node->val)
        {
            first = pre;
        }
        if(first != nullptr && pre->val >= node->val)
        {
            second = node;
        }
        pre = node;
        inorder(node->right);
    }
};
