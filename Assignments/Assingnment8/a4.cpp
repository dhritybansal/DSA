// //Q4. There are different ways to look at a binary tree. The right view of a binary tree contains
// the set of nodes that will be visible if you look at the binary tree from the right side. Given
// the root node of a binary tree, return an array containing the node elements in the right view,
// from top to bottom.

// Testing
// Input Format
// The first line contains an integer T denoting the number of test cases.
// For each test case, the input has 2 lines:
// The first line contains an integer n denoting the number of nodes in the tree (including the
// NULL nodes).
// The second line contains n space-separated integers that will form the binary tree. The
// integers follow level order traversal of the tree where -1 indicates a NULL node.
// Output Format
// For each test case, the output contains a line with space-separated integers representing the
// right view of the binary tree.
// Sample Input
// 6
// 7
// 1 2 -1 4 -1 5 6

// 3
// 6 -1 4
// 7
// 8 -1 9 -1 10 11 12
// 5
// 28 14 11 -1 48
// 1
// 6
// 7
// 3 -1 2 1 5 -1 6
// Expected Output
// 1 2 4 6
// 6 4
// 8 9 10 12
// 28 11 48
// 6
// 3 2 5 6

// TC: O(N)
// SC: O(height)=log n

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *buildTreeLevel(vector<int> &arr)
{
    if (arr.size() == 0 || arr[0] == -1)
        return NULL;

    node *root = new node(arr[0]);
    queue<node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size())
    {
        node *temp = q.front();
        q.pop();

        // left child
        if (arr[i] != -1)
        {
            temp->left = new node(arr[i]);
            q.push(temp->left);
        }
        i++;

        if (i >= arr.size())
            break;

        // right child
        if (arr[i] != -1)
        {
            temp->right = new node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

void rightview(node *root, int lvl, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (lvl == ans.size())
        ans.push_back(root->data);
    rightview(root->right, lvl + 1, ans);
    rightview(root->left, lvl + 1, ans);
}

int main()
{
    int T;
    cout<<"enter test cases ";
    cin >> T;

    while (T--)
    {
        int n;
        cout<<"enter no of nodes ";
        cin >> n; 

        vector<int> arr(n);
        cout<<"enter value of nodes ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        node *root = buildTreeLevel(arr);
        vector<int> ans;
        rightview(root, 0, ans);
        cout<<"right nodes are ";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}
