#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

vector<int> next_greater_idx(deque<int> v)
{
    stack<int> pos;
    for (int i = 0; i < v.size(); ++i)
    {
        while (!pos.empty() && v[i] > v[pos.top()])
        {
            v[pos.top()] = i;
            pos.pop();
        }
        pos.push(i);
    }
    while (!pos.empty())
    {
        v[pos.top()] = v.size();
        pos.pop();
    }
    return vector<int>(v.begin(), v.end());
}
class BinarySearchTree
{
private:
    int data{};
    BinarySearchTree *left{};
    BinarySearchTree *right{};

public:
    BinarySearchTree(int data) : data(data) {}
    BinarySearchTree(deque<int> &preorder) : BinarySearchTree(preorder, next_greater_idx(preorder)) {}
    BinarySearchTree(deque<int> &preorder, const vector<int> &next_greater, int start = 0, int end = -1)
    {
        if (end == -1)
            end = preorder.size() - 1;
        data = preorder[start];
        int split = next_greater[start];
        if (split > end)
            split = end + 1;
        if (start + 1 <= end + 1)
            left = new BinarySearchTree(preorder, next_greater, start + 1, split - 1);
        if (split <= end)
            right = new BinarySearchTree(preorder, next_greater, split, end);
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