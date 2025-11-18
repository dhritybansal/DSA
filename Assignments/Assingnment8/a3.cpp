// Q3. Given a binary tree, return its maximum depth. The depth of a binary tree is the number
// of nodes from the root node to any of the leaf nodes. The maximum depth is the maximum of
// the depths across all the paths.
// Example:

// Testing
// Input Format
// The first line contains an integer T denoting the number of test cases.
// For each test case, the input has 2 lines:
// The first line contains an integer n denoting the number of nodes in the tree (including the
// NULL nodes).
// The second line contains n space-separated integers that will form the binary tree. The
// integers follow level order traversal of the tree where -1 indicates a NULL node.
// Output Format
// For each test case, the output has an integer denoting the maximum depth of the tree.
// Sample Input
// 5
// 12

// 1 2 3 4 5 6 -1 -1 -1 7 -1 8
// 7
// 1 2 -1 4 -1 5 6
// 7
// 8 -1 9 -1 10 11 12
// 5
// 28 14 11 -1 48
// 1
// 6
// Expected Output
// 4
// 4
// 4
// 3
// 1


#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node *left, *right;

    node(int d) {
        data = d;
        left = right = NULL;
    }
};

// Function to build tree from level order input including -1
node* buildTreeLevel(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return NULL;

    node* root = new node(arr[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        node* temp = q.front();
        q.pop();

        // left child
        if (arr[i] != -1) {
            temp->left = new node(arr[i]);
            q.push(temp->left);
        }
        i++;

        if (i >= arr.size()) break;

        // right child
        if (arr[i] != -1) {
            temp->right = new node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

int maxdepth(node* root) {
    if (root == NULL) return 0;
    int left = maxdepth(root->left);
    int right = maxdepth(root->right);
    return 1 + max(left, right);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        node* root = buildTreeLevel(arr);
        cout << maxdepth(root) << endl;
    }

    return 0;
}
