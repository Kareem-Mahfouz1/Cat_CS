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
                node = nullptr;
            else if (!node->right)
                node = node->left;
            else if (!node->left)
                node = node->right;
            else
            {
                auto mn = node->right->min();
                node->data = mn->data;
                node->right = delete_node(node->data, node->right);
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
    vector<int> v = {100, 70, 60, 75};
    return 0;
}