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
        reverse(str.begin(), str.end());
        int idx = 0;
        trie *t = this;
        while (idx != str.length())
        {
            int cur = str[idx] - 'a';
            if (!t->child[cur])
                t->child[cur] = new trie();

            t = t->child[cur];
            idx++;
        }
        t->is_leaf = true;
    }
    bool suffix_exist(string str)
    {
        reverse(str.begin(), str.end());
        int idx = 0;
        trie *t = this;
        while (idx != str.length())
        {
            int cur = str[idx] - 'a';
            if (t->child[cur] == 0)
                return false;

            t = t->child[cur];
            idx++;
        }
        return true;
    }
};
int main()
{
    trie ss;
    ss.insert("abcde");
    ss.insert("xyzmn");
    ss.insert("sjfok");
    cout << ss.suffix_exist("cde") << endl;
    cout << ss.suffix_exist("zm") << endl;
    cout << ss.suffix_exist("fok") << endl;

    return 0;
}
