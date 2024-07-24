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
            else
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
};
int main()
{

    return 0;
}
