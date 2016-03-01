#include <iostream>
/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 */
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * 		int val;
 *     	TreeNode *left;
 *     	TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
	public:
    bool isValidBST(TreeNode* root) 
    {   
        inOrder(root); 
        return isValid;
    }   
    private:
    bool isValid = true;    
    int val;
    bool firstNode = true;
	//中序遍历后应该是升序
    void inOrder(TreeNode* root) 
    {   
        if(root == NULL) return;
        inOrder(root->left);
        if(firstNode)
        {   
            firstNode = false;
        }   
        else
        {   
            if(root->val <= val) isValid = false;  //如果中序遍历时，当前输出结点小于等于前继结点，则为false
        }   
        val = root->val;
        inOrder(root->right);
    }
};
