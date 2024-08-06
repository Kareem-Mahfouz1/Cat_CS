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
    void print_postorder()
    {
        if (left)
            left->print_postorder();
        if (right)
            right->print_postorder();
        cout << data;
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
    void level_order_traverstal()
    {
        queue<BinaryTree *> q;
        q.push(this);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            cout << curr->data << " ";
        }
        cout << "\n";
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
    void print_level(int level)
    {
        if (level == 0)
            cout << data;
        else if (level)
        {
            left->print_level(level - 1);
            right->print_level(level - 1);
        }
    }
    void level_order_traversal_recursive()
    {
        int h = tree_height();

        for (int level = 0; level < h; level++)
        {
            print_level(level);
        }
    }
    void level_order_traversal_spiral()
    {
        deque<BinaryTree *> q;
        q.push_back(this);
        int level = 0;
        bool reverse = true;
        while (!q.empty())
        {
            int size = q.size();
            cout << "Level " << level << ": ";
            while (size--)
            {
                BinaryTree *curr;
                if (reverse)
                { // reversed
                    curr = q.back();
                    q.pop_back();
                    if (curr->left)
                        q.push_front(curr->left);
                    if (curr->right)
                        q.push_front(curr->right);
                    cout << curr->data << " ";
                }
                else
                { // normal
                    curr = q.front();
                    q.pop_front();
                    if (curr->right)
                        q.push_back(curr->right);
                    if (curr->left)
                        q.push_back(curr->left);
                    cout << curr->data << " ";
                }
            }
            level++;
            reverse = !reverse;
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
    tree.level_order_traversal_spiral();

    return 0;
}