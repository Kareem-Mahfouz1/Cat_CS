#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

struct BinaryNode
{
    string data{};
    bool full_word{};
    int height{};
    BinaryNode *left{};
    BinaryNode *right{};

    BinaryNode(string data, bool full_word) : data(data), full_word(full_word) {}
    int ch_height(BinaryNode *node)
    {
        if (!node)
            return -1;
        return node->height;
    }
    int update_height()
    {
        return height = 1 + max(ch_height(left), ch_height(right));
    }
    int balance_factor()
    {
        return ch_height(left) - ch_height(right);
    }
};
class AVLTree
{
private:
    BinaryNode *root{};
    BinaryNode *right_rotation(BinaryNode *Q)
    {
        BinaryNode *P = Q->left;
        Q->left = P->right;
        P->right = Q;
        Q->update_height();
        P->update_height();
        return P;
    }
    BinaryNode *left_rotation(BinaryNode *P)
    {
        BinaryNode *Q = P->right;
        P->right = Q->left;
        Q->left = P;
        P->update_height();
        Q->update_height();
        return Q;
    }
    BinaryNode *balance(BinaryNode *node)
    {
        if (node->balance_factor() == 2)
        {
            if (node->left->balance_factor() == -1)
                node->left = left_rotation(node->left);

            node = right_rotation(node);
        }
        else if (node->balance_factor() == -2)
        {
            if (node->right->balance_factor() == 1)
                node->right = right_rotation(node->right);

            node = left_rotation(node);
        }
        return node;
    }
    BinaryNode *insert_node(string target, bool full_word, BinaryNode *node)
    {
        if (target < node->data)
        {
            if (!node->left)
                node->left = new BinaryNode(target, full_word);
            else
                node->left = insert_node(target, full_word, node->left);
        }
        else if (target > node->data)
        {
            if (!node->right)
                node->right = new BinaryNode(target, full_word);
            else
                node->right = insert_node(target, full_word, node->right);
        }
        node->update_height();
        return balance(node);
    }
    BinaryNode *delete_node(string target, BinaryNode *node)
    {
        if (!node)
            return nullptr;

        if (target < node->data)
            node->left = delete_node(target, node->left);
        else if (target > node->data)
            node->right = delete_node(target, node->right);
        else
        {
            BinaryNode *tmp = node;
            if (!node->left && !node->right)
                node = nullptr;
            else if (!node->right)
                node = node->left;
            else if (!node->left)
                node = node->right;
            else
            {
                BinaryNode *mn = min_node(node->right);
                node->data = mn->data;
                node->right = delete_node(node->data, node->right);
                tmp = nullptr;
            }
            if (tmp)
                delete tmp;
        }
        if (node)
        {
            node->update_height();
            node = balance(node);
        }
        return node;
    }
    BinaryNode *min_node(BinaryNode *cur)
    {
        while (cur && cur->left)
            cur = cur->left;
        return cur;
    }
    int search(string word, BinaryNode *node)
    {
        if (word < node->data)
        {
            if (node->left)
                return search(word, node->left);
            else
                return -1;
        }
        else if (word > node->data)
        {
            if (node->right)
                return search(word, node->right);
            else
                return -1;
        }
        else
            return node->full_word;
    }
    void insert(string value, bool full_word)
    {
        if (!root)
            root = new BinaryNode(value, full_word);
        else
            root = insert_node(value, full_word, root);
    }

public:
    void insert_string(string value)
    {
        string cur = "";
        for (int i = 0; i < value.size(); i++)
        {
            cur += value[i];
            insert(cur, i == value.size() - 1);
        }
    }
    bool word_exist(string word)
    {
        return search(word, root) == 1;
    }
    bool prefix_exist(string pre)
    {
        return search(pre, root) != -1;
    }
};
int main()
{
    AVLTree tree;
    tree.insert_string("hello");
    tree.insert_string("xyzm");
    cout << tree.word_exist("hello") << " ";
    cout << tree.word_exist("hi") << " ";
    cout << tree.prefix_exist("xy") << " ";
    cout << tree.prefix_exist("awd") << " ";

    return 0;
}
