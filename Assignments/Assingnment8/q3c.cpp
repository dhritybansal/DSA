//Maximum depth of BST
//tc=O(n)and sc=O(log(n))
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

node* insert(node* root, int data) {
    if (root == nullptr)
        return new node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int maxDepth(node* root) {
    if (root == nullptr)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int main() {
    node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Maximum Depth (Height) of the BST: " << maxDepth(root) << endl;

    return 0;
}
