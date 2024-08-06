#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>
using namespace std;

class BinaryTree
{
private:
    int data{};
    BinaryTree *left{};
    BinaryTree *right{};

public:
    BinaryTree(int data) : data(data) {}
    BinaryTree(string postfix)
    {
        for (int i = 0; i < postfix.size(); ++i)
        {
        }
    }

    void print_inorder()
    {
        if (left)
            left->print_inorder();
        cout << data << " ";
        if (right)
            right->print_inorder();
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
    void print_inorder_iterative()
    {
        stack<pair<BinaryTree *, bool>> st;
        st.push({this, false});
        while (!st.empty())
        {
            BinaryTree *curr = st.top().first;
            bool is_done = st.top().second;
            st.pop();
            if (is_done)
                cout << curr->data << " ";
            else
            {
                if (curr->right)
                    st.push({curr->right, false});

                st.push({curr, true});

                if (curr->left)
                    st.push({curr->left, false});
            }
        }
        cout << "\n";
    }
    void left_boundry()
    {
        cout << this->data;
        if (left)
            left->left_boundry();
        else if (right)
            right->left_boundry();
    }

    ~BinaryTree() { clear(); }
};

int main()
{
    BinaryTree tree(1);
    tree.add({2, 4}, {'L', 'L'});
    tree.add({2, 5}, {'L', 'R'});
    tree.add({3, 6}, {'R', 'R'});
    tree.add({3, 7}, {'R', 'L'});
    tree.left_boundry();
    return 0;
}