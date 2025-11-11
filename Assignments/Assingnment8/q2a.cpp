// Search a given item (Recursive & Non-Recursive)
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
node* insert(node *root, int data)
{
    if (root == nullptr)
        return new node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

bool searchRecursive(node *root, int key)
{
    if (root == NULL)
        return false;
    else if (root->data == key)
    {
        return true;
    }
    else if (root->data < key)
    {
        return searchRecursive(root->right, key);
    }
    else
        return searchRecursive(root->left, key);
}

bool searchNonRecursive(node *root, int key)
{
    while (root != nullptr)
    {
        if (root->data == key)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
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

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    cout << "\nUsing Recursive Search: ";
    if (searchRecursive(root, key))
        cout << "Found!\n";
    else
        cout << "Not Found!\n";

    cout << "Using Non-Recursive Search: ";
    if (searchNonRecursive(root, key))
        cout << "Found!\n";
    else
        cout << "Not Found!\n";

    return 0;
}