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
    void insert(string str, int idx = 0)
    {
        if (idx == str.length())
            is_leaf = true;
        else
        {
            int cur = str[idx] - 'a';
            if (child[cur] == 0)
                child[cur] = new trie();
            child[cur]->insert(str, idx + 1);
        }
    }
    bool word_exist(string str, int idx = 0)
    {
        if (idx == str.size())
            return is_leaf;

        int cur = str[idx] - 'a';
        if (child[cur] == 0)
            return false;

        return child[cur]->word_exist(str, idx + 1);
    }
    bool prefix_exist(string str, int idx = 0)
    {
        if (idx == str.size())
            return true;

        int cur = str[idx] - 'a';
        if (child[cur] == 0)
            return false;

        return child[cur]->prefix_exist(str, idx + 1);
    }
    string first_word_prefix(const string &str)
    {
        trie *t = this;
        for (int idx = 0; idx < str.length(); idx++)
        {
            int ch = str[idx] - 'a';
            if (!t->child[ch])
                break;

            if (t->child[ch]->is_leaf)
                return str.substr(0, idx + 1);

            t = t->child[ch];
        }
        return str;
    }
};
int main()
{
    trie ss;
    ss.insert("xyz");
    ss.insert("xyzea");
    ss.insert("a");
    ss.insert("bc");
    cout << ss.first_word_prefix("x") << endl;
    cout << ss.first_word_prefix("xyzabc") << endl;

    return 0;
}
