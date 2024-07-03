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

public:
    BinarySearchTree(int data) : data(data) {}
    void print_inorder()
    {
        if (left)
            left->print_inorder();
        cout << data << " ";
        if (right)
            right->print_inorder();
    }
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
    int min()
    {
        if (left)
            return left->min();
        else
            return data;
    }
    bool find_chain(vector<BinarySearchTree *> &ancestors, int target)
    {
        ancestors.push_back(this);

        if (target == data)
            return true;
        if (target < data)
            return left && left->find_chain(ancestors, target);

        return right && right->find_chain(ancestors, target);
    }
    BinarySearchTree *get_next(vector<BinarySearchTree *> &ancestors)
    {
        if (ancestors.empty())
            return nullptr;

        auto node = ancestors.back();
        ancestors.pop_back();
        return node;
    }
    pair<bool, int> succesor(int target)
    {
        vector<BinarySearchTree *> ancestors;
        if (!find_chain(ancestors, target))
            return {false, -1};

        auto child = get_next(ancestors);

        if (child->right)
            return {true, child->right->min()};

        auto parent = get_next(ancestors);
        while (parent && parent->right == child)
            child = parent, parent = parent->get_next(ancestors);
        if (parent)
            return {true, parent->data};
        return {false, -1};
    }
};

int main()
{

    return 0;
}