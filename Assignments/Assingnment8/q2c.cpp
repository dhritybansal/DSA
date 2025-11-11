//Minimum element of the BST
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

int minelement(node* root){
    int ele=INT_MAX;
    while(root!=nullptr){
        ele=min(ele,root->data);
        root=root->left;
        
    }
    return ele;
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

cout<<"max ele is "<<minelement(root);
    return 0;
}