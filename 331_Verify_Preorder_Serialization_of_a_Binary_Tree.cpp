#include <string>
using namespace std;
//One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//
//     _9_
//    /   \
//   3     2
//  / \   / \
// 4   1  #  6
/// \ / \   / \
//# # # #   # #
//For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
//Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
//
//Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//
//You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
//
//Example 1:
//"9,3,4,#,#,1,#,#,2,#,6,#,#"
//Return true
//
//Example 2:
//"1,#"
//Return false
//
//Example 3:
//"9,#,#,1"
//Return false
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return true;
        stack<char> st;
        for(int i = 0; i < preorder.size(); ++i)
        {
            char a = preorder[i++];
            while(!(i >= preorder.size() || preorder[i] == ',')) {++i;}
            if(st.size() == 1 && st.top() == '#') return false;
            if(a != '#') st.push(a);
            else
            {
                while(true)
                {
                    if(!st.empty() && st.top() == '#') 
                    {
                        st.pop();
                        if(!st.empty()) st.pop();
                    }
                    else break;
                }
                st.push('#');
            }
        }
        return (st.size() == 1 && st.top() == '#');
    }
};
