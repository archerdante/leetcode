#include <iostream>
using namespace std;
//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//        _______3______
//       /              \
//    ___5__          ___1__
//   /      \        /      \
//   6      _2       0       8
//         /  \
//         7   4
//For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == nullptr || q == nullptr) return nullptr;
        vector<TreeNode *> path;
        vector<vector<TreeNode *> > lists;
        findPath(root, p, q, path, lists);
        if(lists.size() != 2) return nullptr;
        return findLastCommonNode(lists[0],lists[1]);
    }
private:
    void findPath(TreeNode* node, TreeNode* p, TreeNode* q, vector<TreeNode *> &path, vector<vector<TreeNode *> > &lists)
    {
        if(lists.size() >=2) return;
        path.push_back(node);
        if(node == p || node == q) lists.push_back(path);
        if(node->left != nullptr) findPath(node->left, p, q, path, lists);
        if(node->right != nullptr) findPath(node->right, p, q, path, lists);
        path.pop_back();
    }
    TreeNode* findLastCommonNode(vector<TreeNode *> list1, vector<TreeNode *> list2)
    {
        int i = 0;
        for(; i < list1.size() && i < list2.size(); i++)
        {
            if(list1[i] != list2[i]) return list1[i - 1];
        }
        if(i >= list1.size()) return list1.back();
        if(i >= list2.size()) return list2.back();
        return nullptr;
    }
};
