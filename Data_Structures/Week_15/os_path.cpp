#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class trie
{
private:
    map<string, trie *> child;
    bool is_leaf{};

public:
    trie()
    {
    }
    void insert(vector<string> &path)
    {
        trie *cur = this;
        for (int idx = 0; idx != path.size(); idx++)
        {
            if (!cur->child.count(path[idx]))
                cur->child[path[idx]] = new trie();

            cur = cur->child[path[idx]];
        }
        cur->is_leaf = true;
    }
    bool subpath_exist(vector<string> &path)
    {
        trie *cur = this;
        for (int idx = 0; idx != path.size(); idx++)
        {
            if (!cur->child.count(path[idx]))
                return false;
            cur = cur->child[path[idx]];
        }
        return true;
    }
};
int main()
{

    return 0;
}
