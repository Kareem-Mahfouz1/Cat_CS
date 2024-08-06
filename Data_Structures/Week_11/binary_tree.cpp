#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
void print_inorder(Node *root)
{
    if (!root)
        return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}
class BinaryTree
{
private:
    Node *root{};

public:
    BinaryTree(int value) : root(new Node(value)) {}
    void print()
    {
        print_inorder(root);
    }
    void add(vector<int> vals, string path)
    {
        if (vals.size() != path.size())
            return;

        auto ch = path.begin();
        auto num = vals.begin();
        Node *curr = root;
        while (ch != path.end())
        {
            if (*ch == 'R')
            {
                curr->right = new Node(*num);
                curr = curr->right;
            }
            else if (*ch == 'L')
            {
                curr->left = new Node(*num);
                curr = curr->left;
            }
            else
                return;
            ch++;
            num++;
        }
    }
};

int main()
{
    string path = "LLR";
    vector<int> nums = {1, 2, 3};
    BinaryTree bin(0);
    bin.add(nums, path);
    bin.print();
    return 0;
}