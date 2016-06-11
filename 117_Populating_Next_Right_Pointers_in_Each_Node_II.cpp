#include <deque>
using namespace std;
//Follow up for problem "Populating Next Right Pointers in Each Node".
//
//What if the given tree could be any binary tree? Would your previous solution still work?
//
//Note:
//
//You may only use constant extra space.
//For example,
//Given the following binary tree,
//         1
//       /  \
//      2    3
//     / \    \
//    4   5    7
//After calling your function, the tree should look like:
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \    \
//    4-> 5 -> 7 -> NULL
/**
 ** Definition for binary tree with next pointer.
 ** struct TreeLinkNode {
 **  int val;
 **  TreeLinkNode *left, *right, *next;
 **  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 ** };
 **/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        int now = 1, next = 0;
        deque<TreeLinkNode*> myQue;
        myQue.push_back(root);
        while(!myQue.empty())
        {
            TreeLinkNode *node = myQue.front();
            myQue.pop_front();
            now--;
            if(now > 0) node->next = myQue.front();
            if(node->left) myQue.push_back(node->left),next++;
            if(node->right) myQue.push_back(node->right),next++;
            if(now == 0)
            {
                now = next;
                next = 0;
            }
        }
    }
};
