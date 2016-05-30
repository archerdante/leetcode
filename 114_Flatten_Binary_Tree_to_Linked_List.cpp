#include <vector>
using namespace std;
//Given a binary tree, flatten it to a linked list in-place.
//
//For example,
//Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* newLeaf = new TreeNode(0);
        TreeNode* newHead = newLeaf;
        dfs(root, &newLeaf);
        delete newHead;
        newHead = NULL;
    }
private:
    void dfs(TreeNode* node, TreeNode **leaf)
    {
        (*leaf)->right = node;
        *leaf = node;
        TreeNode* ll = node->left;
        TreeNode* rr = node->right;
        node->left = NULL;
        node->right = NULL;
        if(ll) dfs(ll, leaf);
        if(rr) dfs(rr, leaf);
    }
};
