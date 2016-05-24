#include <vector>
//Design a data structure that supports the following two operations:
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
//For example:
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//Note:
//You may assume that all words are consist of lowercase letters a-z.
class TrieNode
{
public:
    TrieNode()
    {
        next = vector<TrieNode *>(26, NULL);
        isLeaf = false;
    }
    TrieNode* insertChar(const char c)
    {
        if(!next[c - 'a']) next[c - 'a'] = new TrieNode();
        return next[c - 'a'];
    }
    inline TrieNode* getNode(const char c)
    {
        return next[c - 'a'];
    }
    inline vector<TrieNode *>& getNext()
    {
        return next;
    }
    inline void setLeaf(bool flag = true)
    {
        isLeaf = flag;
    }
    inline bool getIsLeaf()
    {
        return isLeaf;
    }
private:
    vector<TrieNode *> next;
    bool isLeaf;
};
class Trie
{
public:
    Trie():root(new TrieNode()){}
    void insertWord(string &word)
    {
        TrieNode *node = root;
        for(auto &a: word)
        {
            node = node->insertChar(a);
        }
        node->setLeaf();
    }
    bool searchWord(string &word)
    {
        if(word.empty()) return false;
        return dfs(word, 0, word.size(), root);
    }
private:
    bool dfs(string &word, const int i, const int N, TrieNode *node)
    {
        assert(i < N);
        if(i == N - 1)
        {
            if(word[i] == '.')
            {
                for(auto a : node->getNext())
                {
                    if(a && a->getIsLeaf()) return true;
                }
                return false;
            }
            if(node->getNode(word[i]) && node->getNode(word[i])->getIsLeaf()) return true;
            else return false;
        }
        if(word[i] == '.')
        {
            for(auto a : node->getNext())
            {
                if(a && dfs(word, i+1, N, a)) return true;
            }
            return false;
        }
        if(node->getNode(word[i]) && dfs(word, i+1, N, node->getNode(word[i]))) return true;
        else return false;
    }
private:
    TrieNode *root;
};
class WordDictionary {
public:
    void addWord(string word) {
        myTrie.insertWord(word);
    }

    bool search(string word) {
        return myTrie.searchWord(word);
    }
private:
    Trie myTrie;
};
