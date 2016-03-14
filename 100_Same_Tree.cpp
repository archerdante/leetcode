#include <iostream>
//Given two binary trees, write a function to check if they are equal or not.
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if(p == NULL || q == NULL)
		{
			return (p == q) ? true : false;
		}
     	//using BFS
     	deque<TreeNode *> qA; 
        deque<TreeNode *> qB; 
        qA.push_back(p);
        qB.push_back(q);
        while(qA.size() && qB.size())
        {   
            TreeNode* pA = qA.front();  
            qA.pop_front(); 
            TreeNode* pB = qB.front();  
            qB.pop_front(); 
            if(pA->val != pB->val)
            {   
                return false;
            }   
            if(pA->left != NULL)
            {   
                if(pB->left == NULL) return false;
                qA.push_back(pA->left);
                qB.push_back(pB->left);
            }   
            else
            {
                if(pB->left != NULL) return false;
            }
            if(pA->right != NULL)
            {   
                if(pB->right == NULL) return false;
                qA.push_back(pA->right);
                qB.push_back(pB->right);
            }   
            else
            {
                if(pB->right != NULL) return false;
            }
        }
        return (qA.size() == qB.size()) ? true : false;
    }
};
