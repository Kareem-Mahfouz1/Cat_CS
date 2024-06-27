#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
#include <cmath>
using namespace std;

struct Node
{
    int data{};
    Node *left{};
    Node *right{};
    Node(int data) : data(data) {}
};

void print_postorder(Node *root)
{
    if (!root)
        return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data << " ";
}
class BinaryTree
{
private:
    Node *root{};
    void print_inorder(Node *curr)
    {
        if (!curr)
            return;
        print_inorder(curr->left);
        cout << curr->data << " ";
        print_inorder(curr->right);
    }
    int Max(Node *curr)
    {
        int curr_max = curr->data;
        if (curr->left)
            curr_max = max(curr_max, Max(curr->left));
        if (curr->right)
            curr_max = max(curr_max, Max(curr->right));
        return curr_max;
    }
    int height(Node *curr, int h = 0)
    {
        if (!curr)
            return -1;

        int lh = height(curr->left, h + 1);
        int rh = height(curr->right, h + 1);

        return max(lh, rh) + 1;
    }
    int count(Node *curr)
    {
        if (!curr)
            return 0;
        int cl = count(curr->left);
        int cr = count(curr->right);
        return cl + cr + 1;
    }
    int count_leaf(Node *curr)
    {
        if (!curr)
            return 0;

        if (!curr->left && !curr->right)
            return 1;
        int cl = count_leaf(curr->left);
        int cr = count_leaf(curr->right);
        return cl + cr;
    }
    bool check(Node *curr, int val)
    {
        if (!curr)
            return false;
        if (val == curr->data)
            return true;
        return check(curr->left, val) || check(curr->right, val);
    }

public:
    BinaryTree(int value) : root(new Node(value)) {}
    void print()
    {
        print_inorder(root);
    }
    void add(vector<int> vals, vector<char> path)
    {
        if (vals.size() != path.size())
            return;

        Node *curr = root;
        for (int i = 0; i < (int)vals.size(); i++)
        {
            if (path[i] == 'R')
            {
                if (!curr->right)
                    curr->right = new Node(vals[i]);
                else
                    assert(curr->right->data == vals[i]);
                curr = curr->right;
            }
            else if (path[i] == 'L')
            {
                if (!curr->left)
                    curr->left = new Node(vals[i]);
                else
                    assert(curr->left->data == vals[i]);
                curr = curr->left;
            }
            else
                return;
        }
    }
    int tree_max()
    {
        return Max(root);
    }
    int tree_height()
    {
        return height(root);
    }
    int total_nodes()
    {
        return count(root);
    }
    int leaf_nodes()
    {
        return count_leaf(root);
    }
    bool is_exist(int val)
    {
        return check(root, val);
    }
    bool is_perfect()
    {
        int levels = tree_height() + 1;
        int nodes = total_nodes();
        return nodes == pow(2, levels) - 1;
    }
};

int main()
{
    BinaryTree tree(1);
    tree.add({2, 4}, {'L', 'L'});
    tree.add({2, 5}, {'L', 'R'});
    tree.add({3, 6}, {'R', 'R'});
    tree.add({3, 7}, {'R', 'L'});
    cout << tree.is_perfect();
    return 0;
}