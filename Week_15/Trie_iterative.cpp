#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;

class trie
{
private:
    static const int MAX_CHAR = 26;
    trie *child[MAX_CHAR];
    bool is_leaf{};

public:
    trie()
    {
        memset(child, 0, sizeof(child));
    }
    void insert(string str)
    {
        trie *cur = this;

        for (int idx = 0; idx < str.size(); ++idx)
        {
            int ch = str[idx] - 'a';
            if (!cur->child[ch])
                cur->child[ch] = new trie();
            cur = cur->child[ch];
        }
        cur->is_leaf = true;
    }
    bool word_exist(string str)
    {
        trie *cur = this;

        for (int idx = 0; idx < str.size(); ++idx)
        {
            int ch = str[idx] - 'a';
            if (!cur->child[ch])
                return false;
            cur = cur->child[ch];
        }
        return cur->is_leaf;
    }
    bool prefix_exist(string str)
    {
        trie *cur = this;

        for (int idx = 0; idx < str.size(); ++idx)
        {
            int ch = str[idx] - 'a';
            if (!cur->child[ch])
                return false;
            cur = cur->child[ch];
        }
        return true;
    }
};
int main()
{

    return 0;
}
