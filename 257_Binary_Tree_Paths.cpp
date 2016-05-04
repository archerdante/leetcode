#include <vector>
#include <string>
using namespace std;
//Given a binary tree, return all root-to-leaf paths.
//For example, given the following binary tree:
//   1
// /   \
//2     3
// \
//  5
//All root-to-leaf paths are:
/["1->2->5", "1->3"]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        vector<int> path;
        vector<vector<int> > ret;
        if(!root) return paths;
        dfs(root, path, ret);
        for(auto &a : ret)
        {
            string temp;
            vector<int>::iterator it = a.begin();
            for(; it != a.end() - 1; ++it)
            {
                temp += to_string(*it) + "->";
            }
            temp += to_string(*it);
            paths.push_back(temp);
        }
        return paths;
    }
private:
    void dfs(TreeNode *node, vector<int> &path, vector<vector<int> > &ret)
    {
        path.push_back(node->val);
        if(node->left) dfs(node->left, path, ret);
        if(node->right) dfs(node->right, path, ret);
        if(!node->left && !node->right) ret.push_back(path);
        path.pop_back();
    }
};
