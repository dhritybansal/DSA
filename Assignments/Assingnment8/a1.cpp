// //Q1. Given the root of a binary tree, return the sum of all left leaves. A leaf is a node with no
// children. A left leaf is a leaf that is the left child of another node.
// Example:

// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left, *right;

    node(int x) {
        data = x;
        left = right = NULL;
    }
};

node* buildTreeLevel(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return NULL;

    node* root = new node(arr[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        node* temp = q.front();
        q.pop();

        // Left child
        if (arr[i] != -1) {
            temp->left = new node(arr[i]);
            q.push(temp->left);
        }
        i++;

        if (i >= arr.size()) break;

        // Right child
        if (arr[i] != -1) {
            temp->right = new node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

int sumOfLeftLeaves(node* root) {
    if (root == NULL) return 0;

    int sum = 0;

    if (root->left &&
        root->left->left == NULL &&
        root->left->right == NULL)
        sum += root->left->data;

    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
int main() {
    int n;
    cin >> n;               

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    node* root = buildTreeLevel(arr);

    cout << sumOfLeftLeaves(root);

    return 0;
}