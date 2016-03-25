#include <iostream>
//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        string temp = "";
        string::iterator it = path.begin();
        for(; it != path.end(); it++)
        {
            if((*it) == '/')
            {
                adjustVec(temp, vec);
            }
            else
            {
                temp.push_back((*it));
            }
        }
        adjustVec(temp, vec);
        string ret = "";
        for(int i = 0; i < vec.size(); i++)
        {
            ret += "/"+vec[i];
        }
        if(vec.size() == 0) return "/";
        return ret;
    }
private:
    void adjustVec(string &temp, vector<string> &vec)
    {
        if(temp == ".")
        {}
        else if (temp == "..")
        {
            if(vec.size() > 0) vec.pop_back();
        }
        else if(temp != "")
        {
            vec.push_back(temp);
        }
        temp.clear();
    }
};
