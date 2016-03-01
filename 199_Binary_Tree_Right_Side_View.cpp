#include <iostream>
#include <vector>
/**
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
 * You should return [1, 3, 4].
 */
//Definition for a binary tree node.
using namespace std;
struct TreeNode 
{
 	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution 
{
	public:
    vector<int> rightSideView(TreeNode* root) 
	{
		vector<int> v;
		preorderFromRight(root, v);
		return v;
	}
	private:
	int deepth = 0;
	int max = -1;
	//preorder from right and record deepth 	
	void preorderFromRight(TreeNode* root, vector<int> &v) 
	{
		if(root == NULL) return;	
		if(deepth > max)
		{
			//cout << root->val;	
			v.push_back(root->val);
			max = deepth;
		}
		deepth++;
		preorderFromRight(root->right,v);	
		preorderFromRight(root->left,v);	
		deepth--;
		return;
	}
};
int main()
{
	TreeNode *node_1 = new TreeNode(1);
	TreeNode *node_2 = new TreeNode(2);
	TreeNode *node_3 = new TreeNode(3);
	TreeNode *node_4 = new TreeNode(4);
	TreeNode *node_5 = new TreeNode(5);
	node_1->left = node_2;
	node_1->right = node_3;
	node_2->right = node_5;
	node_3->right = node_4;
	Solution s;
	s.rightSideView(node_1);
	delete node_1;
	delete node_2;
	delete node_3;
	delete node_4;
	delete node_5;
}
