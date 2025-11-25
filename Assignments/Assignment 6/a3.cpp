// 3. Given a Doubly linked list containing n nodes. The task is to reverse every group of k
// nodes in the list. If the number of nodes is not a multiple of k then left-out nodes, in the
// end should be considered as a group and must be reversed.
// https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/
// Example 1:
// Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL, k = 2
// Output: 2 <-> 1 <-> 4 <-> 3 <-> 6 <-> 5 <-> NULL.
// Example 2:
// Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL, k = 4
// Output: 4 <-> 3 <-> 2 <-> 1 <-> 6 -> 5 <-> NULL.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

Node* reverseGroup(Node* head, int k) {
    if (!head) return NULL;

    Node *current = head, *next = NULL, *prev = NULL;
    int count = 0;

    while (current && count < k) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseGroup(next, k);
        if (head->next)
            head->next->prev = head;
    }

    return prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    cout << "Original: ";
    printList(head);

    int k = 4;
    head = reverseGroup(head, k);

    cout << "Reversed in groups: ";
    printList(head);

    return 0;
}
