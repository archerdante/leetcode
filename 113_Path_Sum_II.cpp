#include <vector>
using namespace std;
//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//For example:
//Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//return
//[
//   [5,4,11,2],
//   [5,8,4,5]
//]
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        if(root == nullptr) return ret;
        vector<int> path;
        dfs(ret,path,sum,root);
        return ret;
    }
private:
    void dfs(vector<vector<int> > &ret, vector<int> &path, const int sum, TreeNode *node)
    {
        path.push_back(node->val);
        if(!node->left&&!node->right&&node->val == sum) 
        {
            ret.push_back(path);
        }
        if(node->left) dfs(ret, path, sum - node->val, node->left);
        if(node->right) dfs(ret, path, sum - node->val, node->right);
        path.pop_back();
    }
};
