#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <deque>
using namespace std;

class BinaryTree
{
private:
    int data{};
    BinaryTree *left{};
    BinaryTree *right{};

public:
    BinaryTree(int data) : data(data) {}
    BinaryTree(deque<int> &preorder, deque<int> &inorder, int start = 0, int end = -1)
    {
        if (end == -1)
            end = inorder.size() - 1;
        data = preorder.front();
        preorder.pop_front();
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == data)
            {
                if (i > start)
                    left = new BinaryTree(preorder, inorder, start, i - 1);
                if (i < end)
                    right = new BinaryTree(preorder, inorder, i + 1, end);
                break;
            }
        }
    }
    int tree_height()
    {
        int res = 0;
        if (left)
            res = max(res, 1 + left->tree_height());
        if (right)
            res = max(res, 1 + right->tree_height());
        return res;
    }
    void add(vector<int> values, vector<char> direction)
    {
        assert(values.size() == direction.size());
        BinaryTree *current = this;
        for (int i = 0; i < (int)values.size(); ++i)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new BinaryTree(values[i]);
                else
                    assert(current->left->data == values[i]);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new BinaryTree(values[i]);
                else
                    assert(current->right->data == values[i]);
                current = current->right;
            }
        }
    }
    void clear()
    {
        if (!left && !right)
            return;
        if (left)
        {
            left->clear();
            delete left;
            left = nullptr;
        }
        if (right)
        {
            right->clear();
            delete right;
            right = nullptr;
        }
    }
    void level_order_traverstal2()
    {
        queue<BinaryTree *> q;
        q.push(this);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            cout << "Level " << level << ": ";
            while (size--)
            {
                auto curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                cout << curr->data << " ";
            }
            level++;
            cout << "\n";
        }
        cout << "\n";
    }
    ~BinaryTree() { clear(); }
};

int main()
{
    BinaryTree tree(1);
    tree.add({2, 4, 8}, {'L', 'L', 'L'});
    tree.add({2, 4, 9}, {'L', 'L', 'R'});
    tree.add({2, 5, 10}, {'L', 'R', 'L'});
    tree.add({2, 5, 11}, {'L', 'R', 'R'});
    tree.add({3, 6, 12}, {'R', 'L', 'L'});
    tree.add({3, 6, 13}, {'R', 'L', 'R'});
    tree.add({3, 7, 14}, {'R', 'R', 'L'});
    tree.add({3, 7, 15}, {'R', 'R', 'R'});

    return 0;
}