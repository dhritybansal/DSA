// In-order predecessor of a given node the BST
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

node *inorderPredecessor(node *root, node *x)
{
    // Case 1: if left subtree exists → predecessor is max of left subtree
    if (x->left != nullptr)
    {
        node *temp = x->left;
        while (temp && temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }

    // Case 2: no left subtree → find from root
    node *predecessor = nullptr;

    while (root != nullptr)
    {
        if (x->data < root->data)
        {
            root = root->left;
        }
        else if (x->data > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else
            break;
    }
    return predecessor;
}

int main()
{
    node *root = nullptr;
    vector<int> arr = {50, 30, 20, 40, 70, 60, 80};
    for (int it : arr)
        root = insert(root, it);

    node *x = root->left;
    node *pred = inorderPredecessor(root, x);

    cout << "Node: " << x->data << endl;
    if (pred)
        cout << "Inorder Predecessor: " << pred->data << endl;
    else
        cout << "Inorder Predecessor: None" << endl;

    return 0;
}
