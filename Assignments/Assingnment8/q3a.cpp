//Insert an element (no duplicates are allowed)
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

node* buildbst(vector<int>&arr){
    node* root=NULL;
    for(int it:arr){
     root=insert(root,it);
    } return root;
}
void inorder(node* root){
    if(root==NULL)return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
  vector<int>arr={3,2,1,5,6,4};
  node* root=buildbst(arr);
   root=insert(root,7);
   inorder(root);
   return 0;
}