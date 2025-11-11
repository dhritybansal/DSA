// 4. Write a program to determine whether a given binary tree is a BST or not.
//tc=O(n)and sc=O(log(n))
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
        left = nullptr;
        right = nullptr;
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

bool helper(node *root, node *min, node *max)
{
    if (root == NULL)
        return true;
    if (min != NULL && root->data <= min->data)
        return false;
    if (max != NULL && root->data >= max->data)
        return false;
    return (helper(root->left, NULL, root) && helper(root->right, root, NULL));
}
bool isvalid(node *root)
{
    return helper(root, NULL, NULL);
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

     if (isvalid(root))
        cout << "The given tree is a VALID BST.\n";
    else
        cout << "The given tree is NOT a BST.\n";


    root->left->right->data = 90;

    if (isvalid(root))
        cout << "The modified tree is a VALID BST.\n";
    else
        cout << "The modified tree is NOT a BST.\n";
    return 0;
}
