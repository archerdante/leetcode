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
        if(!root) return paths;
        dfs(root, path, paths);
        return paths;
    }
private:
    void dfs(TreeNode *node, vector<int> &path, vector<string> &paths)
    {
        path.push_back(node->val);
        if(!node->left && !node->right) 
        {
            string temp;
            vector<int>::iterator it = path.begin();
            for(; it != path.end() - 1; ++it)
            {
                temp += to_string(*it) + "->";
            }
            temp += to_string(*it);
            paths.push_back(temp);
        }
        else
        {
            if(node->left) dfs(node->left, path, paths);
            if(node->right) dfs(node->right, path, paths);
        }
        path.pop_back();
    }
};
