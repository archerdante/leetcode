#include <iostream>
//Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        searchLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = nodeStack.top();
        nodeStack.pop();
        if(node->right) searchLeft(node->right); 
        return node->val;
    }
private:
    stack<TreeNode*> nodeStack;
    void searchLeft(TreeNode* node)
    {
        while(node)
        {
            nodeStack.push(node);
            node = node->left;
        }
    }
};
