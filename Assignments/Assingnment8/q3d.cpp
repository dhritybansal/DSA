// Minimum depth of BST
// tc=O(n)and sc=O(log(n))
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

node *insert(node *root, int data)
{
    if (root == nullptr)
        return new node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int minDepth(node *root)
{
    if (root == nullptr)
        return 0;

    // If one child is NULL, we must take the other
    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    // Both children exist → take min
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main()
{
    node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Minimum Depth (Height) of the BST: " << minDepth(root) << endl;

    return 0;
}
