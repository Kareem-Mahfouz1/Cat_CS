#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

class trie
{
private:
    map<int, trie *> child;
    bool is_leaf{};

public:
    trie()
    {
    }
    void insert(string str, int idx = 0)
    {
        if (idx == str.length())
            is_leaf = true;
        else
        {
            int cur = str[idx] - 'a';
            if (!child.count(cur))
                child[cur] = new trie();
            child[cur]->insert(str, idx + 1);
        }
    }
    bool word_exist(string str, int idx = 0)
    {
        if (idx == str.size())
            return is_leaf;

        int cur = str[idx] - 'a';
        if (!child.count(cur))
            return false;

        return child[cur]->word_exist(str, idx + 1);
    }
    bool prefix_exist(string str, int idx = 0)
    {
        if (idx == str.size())
            return true;

        int cur = str[idx] - 'a';
        if (!child.count(cur))
            return false;

        return child[cur]->prefix_exist(str, idx + 1);
    }
};
int main()
{

    return 0;
}
