#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

struct BinaryNode
{
    int data{};
    int height{};
    int count{1};
    BinaryNode *left{};
    BinaryNode *right{};

    BinaryNode(int data) : data(data) {}

    int ch_height(BinaryNode *node)
    {
        if (!node)
            return -1;
        return node->height;
    }
    int ch_count(BinaryNode *node)
    {
        if (!node)
            return 0;
        return node->count;
    }
    void update_height()
    {
        height = 1 + max(ch_height(left), ch_height(right));
        count = 1 + ch_count(right) + ch_count(left);
    }
    int balance_factor()
    {
        return ch_height(left) - ch_height(right);
    }
};
class AVLTree
{
private:
    BinaryNode *root{};
    BinaryNode *right_rotation(BinaryNode *Q)
    {
        BinaryNode *P = Q->left;
        Q->left = P->right;
        P->right = Q;
        Q->update_height();
        P->update_height();
        return P;
    }
    BinaryNode *left_rotation(BinaryNode *P)
    {
        BinaryNode *Q = P->right;
        P->right = Q->left;
        Q->left = P;
        P->update_height();
        Q->update_height();
        return Q;
    }
    BinaryNode *balance(BinaryNode *node)
    {
        if (node->balance_factor() == 2)
        {
            if (node->left->balance_factor() == -1)
                node->left = left_rotation(node->left);

            node = right_rotation(node);
        }
        else if (node->balance_factor() == -2)
        {
            if (node->right->balance_factor() == 1)
                node->right = right_rotation(node->right);

            node = left_rotation(node);
        }
        return node;
    }
    BinaryNode *insert_node(int target, BinaryNode *node)
    {
        if (target < node->data)
        {
            if (!node->left)
                node->left = new BinaryNode(target);
            else
                node->left = insert_node(target, node->left);
        }
        else if (target > node->data)
        {
            if (!node->right)
                node->right = new BinaryNode(target);
            else
                node->right = insert_node(target, node->right);
        }
        node->update_height();
        return balance(node);
    }
    BinaryNode *delete_node(int target, BinaryNode *node)
    {
        if (!node)
            return nullptr;

        if (target < node->data)
            node->left = delete_node(target, node->left);
        else if (target > node->data)
            node->right = delete_node(target, node->right);
        else
        {
            BinaryNode *tmp = node;
            if (!node->left && !node->right)
                node = nullptr;
            else if (!node->right)
                node = node->left;
            else if (!node->left)
                node = node->right;
            else
            {
                BinaryNode *mn = min_node(node->right);
                node->data = mn->data;
                node->right = delete_node(node->data, node->right);
                tmp = nullptr;
            }
            if (tmp)
                delete tmp;
        }
        if (node)
        {
            node->update_height();
            node = balance(node);
        }
        return node;
    }
    BinaryNode *min_node(BinaryNode *cur)
    {
        while (cur && cur->left)
            cur = cur->left;
        return cur;
    }
    int upper_bound_count(int target, BinaryNode *node)
    {
        if (!node)
            return 0;
        if (target < node->data)
        {
            int sum = 1;
            if (node->right)
                sum += node->right->count;
            return sum + upper_bound_count(target, node->left);
        }
        return upper_bound_count(target, node->right);
    }

public:
    void insert(int value)
    {
        if (!root)
            root = new BinaryNode(value);
        else
            root = insert_node(value, root);
    }
    void delete_value(int value)
    {
        if (!root)
            return;
        root = delete_node(value, root);
    }
    int count_inversions(vector<int> &nums)
    {
        AVLTree tree;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            tree.insert(nums[i]);
            sum += upper_bound_count(nums[i], root);
        }
        return sum;
    }
};
int main()
{

    return 0;
}
