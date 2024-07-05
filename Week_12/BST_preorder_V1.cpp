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
    BinarySearchTree(deque<int> &preorder, int start = 0, int end = -1)
    {
        if (end == -1)
            end = preorder.size() - 1;

        data = preorder.front();

        for (int i = start + 1; i <= end; i++)
        {
            if (preorder[i] > data)
            {
                if (start + 1 <= i - 1)
                    left = new BinarySearchTree(preorder, start + 1, i - 1);
                if (i <= end)
                    right = new BinarySearchTree(preorder, i, end);
                break;
            }
        }
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
};

int main()
{
    vector<int> v = {100, 70, 60, 75};
    return 0;
}