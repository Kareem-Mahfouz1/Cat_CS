#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

struct BinaryNode
{
    int priority{};
    vector<int> task_ids;
    int height{};
    BinaryNode *left{};
    BinaryNode *right{};

    BinaryNode(int task_id, int priority) : priority(priority)
    {
        task_ids.push_back(task_id);
    }

    int ch_height(BinaryNode *node)
    {
        if (!node)
            return -1;
        return node->height;
    }
    int update_height()
    {
        return height = 1 + max(ch_height(left), ch_height(right));
    }
    int balance_factor()
    {
        return ch_height(left) - ch_height(right);
    }
};
class priotity_queue
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
    BinaryNode *insert_node(int task_id, int priority, BinaryNode *node)
    {
        if (priority < node->priority)
        {
            if (!node->left)
                node->left = new BinaryNode(task_id, priority);
            else
                node->left = insert_node(task_id, priority, node->left);
        }
        else if (priority > node->priority)
        {
            if (!node->right)
                node->right = new BinaryNode(task_id, priority);
            else
                node->right = insert_node(task_id, priority, node->right);
        }
        else
            node->task_ids.push_back(task_id);
        node->update_height();
        return balance(node);
    }
    BinaryNode *delete_node(int target, BinaryNode *node)
    {
        if (!node)
            return nullptr;

        if (target < node->priority)
            node->left = delete_node(target, node->left);
        else if (target > node->priority)
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
                node->priority = mn->priority;
                node->right = delete_node(node->priority, node->right);
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
    BinaryNode *max_node(BinaryNode *cur)
    {
        while (cur && cur->right)
            cur = cur->right;
        return cur;
    }

public:
    void enqueue(int task_id, int priority)
    {
        if (!root)
            root = new BinaryNode(task_id, priority);
        else
            root = insert_node(task_id, priority, root);
    }
    int dequeue()
    {
        if (!root)
            return;
        auto mx = max_node(root);
        assert(!mx->task_ids.empty());
        int res = mx->task_ids.back();
        if (mx->task_ids.empty())
            root = delete_node(mx->priority, root);
        return res;
    }
};
int main()
{

    return 0;
}
