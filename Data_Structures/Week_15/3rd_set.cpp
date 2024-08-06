#include <iostream>
#include <algorithm>
#include <vector>
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
    void insert(string str, int start = 0)
    {
        trie *cur = this;

        for (int idx = start; idx < str.size(); ++idx)
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
    void print_matches(const string &str, int start = 0)
    {
        trie *cur = this;
        for (int idx = start; idx < str.size(); idx++)
        {
            int ch = str[idx] - 'a';
            if (!cur->child[ch])
                return;
            cur = cur->child[ch];
            if (cur->is_leaf)
                cout << str.substr(start, idx - start + 1) << " ";
        }
    }
};
void list_substrs(const string &str, vector<string> &queries)
{
    trie *tree;
    for (int i = 0; i < str.size() - 1; i++)
        tree->insert(str, i);
    for (string item : queries)
    {
        if (tree->prefix_exist(item))
            cout << item << " ";
    }
    cout << endl;
}
void list_substrs_2(const string &str, vector<string> &queries)
{
    trie *tree;
    for (string item : queries)
        tree->insert(item);

    for (int i = 0; i < str.size() - 1; i++)
        tree->print_matches(str, i);
}
int main()
{
}
