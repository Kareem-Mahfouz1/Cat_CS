#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

class BinarySearchTree
{
private:
    int data{};
    BinarySearchTree *left{};
    BinarySearchTree *right{};

public:
    BinarySearchTree(int data) : data(data) {}
    bool search(int target)
    {
        if (target == data)
            return true;
        else if (target < data)
            return left && left->search(target);
        else if (target > data)
            return right && right->search(target);
    }
    void insert(int target)
    {
        if (target < data)
        {
            if (!left)
                left = new BinarySearchTree(target);
            else
                left->insert(target);
        }
        else if (target > data)
        {
            if (!right)
                right = new BinarySearchTree(target);
            else
                right->insert(target);
        }
    }
    BinarySearchTree *min()
    {
        if (left)
            return left->min();
        else
            return this;
    }
    BinarySearchTree *max()
    {
        if (right)
            return left->max();
        else
            return this;
    }
    void special_delete(BinarySearchTree *child)
    {
        data = child->data;
        left = child->left;
        right = child->right;
        delete child;
    }
    BinarySearchTree *delete_node(int target, BinarySearchTree *node)
    {
        if (!node)
            return nullptr;
        if (target < node->data)
            node->left = node->left->delete_node(target, node->left);
        if (target > node->data)
            node->right = node->right->delete_node(target, node->right);
        else
        {
            auto temp = node;
            if (!node->left && !node->right)
                delete node;
            else if (!node->right)
                node->special_delete(node->left);
            else if (!node->left)
                node->special_delete(node->right);
            else
            {
                auto mx = node->left->max(); // predecessor
                node->data = mx->data;
                node->left = delete_node(node->data, node->left);
                temp = nullptr;
            }
            if (temp)
                delete temp;
        }
        return node;
    }
    void delete_value(int target)
    {
        if (target == data && !left && !right)
            return;
        delete_node(target, this);
    }
};

int main()
{
}