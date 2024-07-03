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
    int max()
    {
        if (right)
            return right->max();
        else
            return data;
    }
    int succesor(int target)
    {
        if (target == data)
        {
            return right->min();
        }
        else if (target < data && left)
            return left->succesor(target);
        else if (target > data && right)
            return right->succesor(target);
        else
            return -1;
    }
    void draw(int space = 0, int height = 10) const
    {
        if (this == nullptr)
            return;

        space += height;

        if (right)
            right->draw(space);

        std::cout << std::endl;
        for (int i = height; i < space; i++)
            std::cout << ' ';
        std::cout << data << "\n";

        if (left)
            left->draw(space);
    }
    bool search_iterative(int target)
    {
        stack<BinarySearchTree *> st;
        st.push(this);
        while (!st.empty())
        {
            auto cur = st.top();
            st.pop();
            if (target == cur->data)
                return true;
            else if (target < cur->data)
            {
                if (cur->left)
                    st.push(cur->left);
            }
            else
            {
                if (cur->right)
                    st.push(cur->right);
            }
        }
        return false;
    }
    int kth_smallest(int &k)
    {
        if (k == 0)
            return -1234;

        if (left)
        {
            int res = left->kth_smallest(k);
            return res;
        }
        k--;
        if (k == 0)
            return data;

        if (right)
            return right->kth_smallest(k);

        return -1234;
    }
    int LCA(int a, int b)
    {
        if (a < data && b < data)
            return left->LCA(a, b);
        if (a > data && b > data)
            return right->LCA(a, b);
        return data;
    }
    bool is_bst()
    {
        if (left)
            if (left->data < data)
                return left->is_bst();
            else
                return false;
        if (right)
            if (right->data > data)
                return right->is_bst();
            else
                return false;

        return true;
    }
};

int main()
{
    BinarySearchTree tree(50);
    tree.insert(20);
    tree.insert(60);
    tree.insert(15);
    tree.insert(45);
    tree.insert(70);
    tree.insert(73);
    tree.insert(35);
    cout << tree.is_bst();
    return 0;
}