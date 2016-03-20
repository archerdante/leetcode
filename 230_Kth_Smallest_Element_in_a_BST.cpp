#include <iostream>
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root,k);
        return ret;
    }
private:
    int i = 1;
    int ret = 0;
    void inOrder(TreeNode* p,const int k)
    {
        if(p == NULL || i > k)
        {
            return;
        }
        inOrder(p->left,k);
        if(i == k)
        {
            ret = p->val;
        }
        i++;
        inOrder(p->right,k);
    }
};
