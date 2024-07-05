#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <stack>
using namespace std;

class BinarySearchTree
{
private:
    int data{};
    BinarySearchTree *left{};
    BinarySearchTree *right{};
    BinarySearchTree *parent{};

public:
    BinarySearchTree(int data) : data(data) {}
    void insert(int target)
    {
        if (target < data)
        {
            if (!left)
            {
                left = new BinarySearchTree(target);
                left->parent = this;
            }
            else
                left->insert(target);
        }
        else if (target > data)
        {
            if (!right)
            {
                right = new BinarySearchTree(target);
                right->parent = this;
            }
            else
                right->insert(target);
        }
    }
    int min()
    {
        if (left)
            return left->min();
        else
            return data;
    }
    BinarySearchTree *find_node(int target)
    {
        if (target == data)
            return this;
        if (target < data)
        {
            if (!left)
                return nullptr;
            return left->find_node(target);
        }
        if (!right)
            return nullptr;
        return right->find_node(target);
    }
    pair<bool, int> succesor(int target)
    {
        auto cur = find_node(target);
        if (!cur)
            return {false, -1};
        if (cur->right)
            return {true, cur->right->min()};

        auto parent = cur->parent;
        while (parent && parent->right == cur)
            cur = parent, parent = parent->parent;

        if (parent)
            return {true, parent->data};
        return {false, -1};
    }
};

int main()
{

    return 0;
}