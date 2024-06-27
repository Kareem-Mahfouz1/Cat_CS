#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>
using namespace std;

class BinaryTree
{
private:
    char data{};
    BinaryTree *left{};
    BinaryTree *right{};
    bool is_leaf()
    {
        return !left && !right;
    }

public:
    BinaryTree(int data) : data(data) {}
    BinaryTree(string postfix)
    {
        stack<BinaryTree *> st;
        for (int i = 0; i < postfix.size(); ++i)
        {
            BinaryTree *curr = new BinaryTree(postfix[i]);

            if (!isdigit(postfix[i]))
            {
                curr->right = st.top();
                st.pop();
                curr->left = st.top();
                st.pop();
            }
            st.push(curr);
        }
        auto root = st.top();
        this->data = root->data;
        this->right = root->right;
        this->left = root->left;
    }
    void print_postorder()
    {
        if (left)
            left->print_postorder();
        if (right)
            right->print_postorder();
        cout << data;
    }
    void print_inorder()
    {
        if (left)
            left->print_inorder();
        cout << data;
        if (right)
            right->print_inorder();
    }
    void print_inorder_expression()
    {
        if (left)
        {
            if (!left->is_leaf())
                cout << '(';
            left->print_inorder();
            if (!left->is_leaf())
                cout << ')';
        }
        cout << data;
        if (right)
            if (!right->is_leaf())
                cout << '(';
        right->print_inorder();
        if (!right->is_leaf())
            cout << ')';
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
    ~BinaryTree() { clear(); }
};

int main()
{
    BinaryTree t("451+*");
    t.print_inorder_expression();
    return 0;
}