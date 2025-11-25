// 5. Given a 2D matrix, the task is to convert it into a doubly-linked list with four pointers
// that are next, previous, up, and down, each node of this list should be connected to its
// next, previous, up, and down nodes.

// https://www.geeksforgeeks.org/construct-a-doubly-linked-linked-list-from-2d-
// matrix/?ref=rp

// Input: 2D matrix
// 1 2 3
// 4 5 6
// 7 8 9
// Output:


#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *right, *left, *up, *down;
    Node(int val) {
        data = val;
        right = left = up = down = NULL;
    }
};

Node* constructDLL(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<Node*>> nodes(n, vector<Node*>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nodes[i][j] = new Node(mat[i][j]);

    // Link nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // left link
            if (j > 0)
                nodes[i][j]->left = nodes[i][j - 1];

            // right link
            if (j < m - 1)
                nodes[i][j]->right = nodes[i][j + 1];

            // up link
            if (i > 0)
                nodes[i][j]->up = nodes[i - 1][j];

            // down link
            if (i < n - 1)
                nodes[i][j]->down = nodes[i + 1][j];
        }
    }

   
    return nodes[0][0];
}

void printLinkedGrid(Node* head, int n, int m) {
    Node* row = head;
    for (int i = 0; i < n; i++) {
        Node* col = row;
        for (int j = 0; j < m; j++) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << "\n";
        row = row->down;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = constructDLL(mat);

    cout << "Linked 2D Grid:\n";
    printLinkedGrid(head, 3, 3);

    return 0;
}
