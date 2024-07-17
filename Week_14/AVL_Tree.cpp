#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <stack>
using namespace std;

class AVLTree
{
private:
    int data;
    int height;
    AVLTree *left{};
    AVLTree *right{};
    int ch_height(AVLTree *node)
    {
        if (!node)
            return -1;
        return node->height;
    }
    void update_height()
    {
        height = 1 + max(left->height, right->height);
    }
    int balance_factor()
    {
        return ch_height(left) - ch_height(right);
    }

public:
    AVLTree *right_rotation(AVLTree *node)
    {
        AVLTree *p = node->left;
        node->left = p->right;
        p->right = node;
        node->update_height();
        p->update_height();
        return p;
    }
    AVLTree *left_rotation(AVLTree *node)
    {
        AVLTree *q = node->right;
        node->right = q->left;
        q->left = node;
        node->update_height();
        q->update_height();
        return q;
    }
};

int main()
{

    return 0;
}