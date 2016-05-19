#include <vector>
#include <string>
using namespace std;
//Implement a trie with insert, search, and startsWith methods.
//
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.
class TrieNode {
public:

    TrieNode() {
        
    }
    TrieNode* setNext(const char c)
    {
        if(!next[c - 'a']) next[c - 'a'] = new TrieNode();
        return next[c - 'a'];
    }
    TrieNode* getNext(const char c)
    {
        return next[c - 'a'];
    }
    void setLeaf(bool isL = true)
    {
        isLeaf = true;
    }
    bool getLeaf()
    {
        return isLeaf;
    }
private:
    vector<TrieNode*> next = vector<TrieNode*>(26,NULL);
    bool isLeaf = false;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }


    void insert(string word) {
        TrieNode* node = root;
        for(auto &a : word)
        {
            node = node->setNext(a);
        }
        node->setLeaf();
    }


    bool search(string word) {
        TrieNode *node = root;
        for(auto &a : word)
        {
            node = node->getNext(a);
            if(!node) return false;
        }
        return node->getLeaf();
    }


    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(auto &a : prefix)
        {
            node = node->getNext(a);
            if(!node) return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

