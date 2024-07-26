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
    void get_all_strings(vector<string> &res, string cur = "")
    {
        if (is_leaf)
            res.push_back(cur);
        for (int i = 0; i < MAX_CHAR; i++)
        {
            if (child[i])
                child[i]->get_all_strings(res, cur + (char)(i + 'a'));
        }
    }
    void auto_complete(string str, vector<string> &res)
    {
        trie *cur = this;
        for (int i = 0; i < str.size(); i++)
        {
            int ch = str[i] - 'a';
            if (!cur->child[ch])
                break;
            cur = cur->child[ch];
        }
        cur->get_all_strings(res, str);
    }
    bool word_exist_with_1_change(string &str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            char cpy = str[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (cpy == ch)
                    continue;
                str[i] = ch;
                if (word_exist(str))
                    return true;
            }
            str[i] = cpy;
        }
        return false;
    }
};
int main()
{

    return 0;
}
