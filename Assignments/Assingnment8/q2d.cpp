// In-order sucessor of a given node the BST
#include <iostream>
#include <vector>
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
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

node *inorderSuccessor(node *root, node *x)
{
    // Case 1: right subtree exists
    if (x->right != NULL)
    {
        node *temp = x->right;
        while (temp && temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    // Case 2: no right subtree → search from root
    node *successor = nullptr;

    while (root != nullptr)
    {
        if (x->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (x->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}

int main()
{
    node *root = nullptr;
    vector<int> arr = {50, 30, 20, 40, 70, 60, 80};
    for (int it : arr)
        root = insert(root, it);

    node *x = root->left;

    node *succ = inorderSuccessor(root, x);

    cout << "Node: " << x->data << endl;
    if (succ)
        cout << "Inorder Successor: " << succ->data << endl;
    else
        cout << "Inorder Successor: None" << endl;

    return 0;
}
