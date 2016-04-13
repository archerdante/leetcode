#include <iostream>
#include <vector>
#include <deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if(root == NULL) return ret;
        deque<TreeNode*> list_node;
        list_node.push_back(root);
        zigzag(ret, list_node, RIGHT);
        return ret;
    }
private:
    const int RIGHT = 0;
    const int LEFT = 1;
    void zigzag(vector<vector<int> > &ret, deque<TreeNode*> &list_old, const int direction)
    {
        deque<TreeNode*> list_new;
        vector<int> line;
        while(!list_old.empty())
        {
            TreeNode* temp = list_old.front();
            list_old.pop_front();
            line.push_back(temp->val);
            if(direction == LEFT)
            {
                if(temp->right != NULL) list_new.push_back(temp->right);
                if(temp->left != NULL) list_new.push_back(temp->left);
            }
            else
            {
                if(temp->left != NULL) list_new.push_back(temp->left);
                if(temp->right != NULL) list_new.push_back(temp->right);
            }
        }
        if(!line.empty()) ret.push_back(line);
        if(!list_new.empty()) 
        {
            reverse(list_new.begin(),list_new.end());
            zigzag(ret, list_new, (direction ^ 1));
        } 
    }
};
