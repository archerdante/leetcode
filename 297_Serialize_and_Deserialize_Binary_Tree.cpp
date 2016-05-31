#include <vector>
using namespace std;
//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
//Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//For example, you may serialize the following tree
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
class Codec {
public:

    string serialize(TreeNode* root) {
        string ret = "";
        if(root == nullptr) return ret;
        vector<string> se;
        dfs(se, root);
        const int N = se.size();
        for(int i = 0; i < N - 1; ++i)
        {
            ret.insert(ret.end(), se[i].begin(),se[i].end());
            ret.push_back(',');
        }
        ret.append(se[N-1]);
        ret.insert(ret.begin(),'[');
        ret.push_back(']');
        return ret;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        if(data[0] != '[') return NULL;
        int N = data.size();
        if(data[N-1] != ']') return NULL;
        int i = 1;
        vector<string> se;
        string temp = "";
        while(i < N - 1)
        {
            while(i < N - 1 && data[i] != ',') temp.push_back(data[i++]);
            se.push_back(temp);
            i++;
            temp.clear();
        }
        if(se.empty()) return NULL;
        int index = 0;
        return rdfs(se, index);
    }
private:
    void dfs(vector<string> &se, TreeNode* node)
    {
        se.push_back(to_string(node->val));
        if(node->left) dfs(se, node->left);
        else se.push_back("null");
        if(node->right) dfs(se, node->right);
        else se.push_back("null");
    }
    TreeNode* rdfs(vector<string> &se, int &index)
    {
        if(se[index] == "null" || index >= se.size()) return NULL;
        TreeNode* node = new TreeNode(atoi(se[index].c_str()));
        node->left = rdfs(se, ++index);
        node->right = rdfs(se, ++index);
        return node;
    }
};
