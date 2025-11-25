// //1. Given a Circular linked list. The task is split into two Circular Linked lists. If there are an
// odd number of nodes in the given circular linked list then out of the resulting two halved
// lists, the first list should have one node more than the second list.
// https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/
// Input: 10->4->9
// Output: 10->4 , 9
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int data) {
    Node* newNode = new Node{data, NULL};

    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void splitList(Node* head, Node*& head1, Node*& head2) {
    if (!head || head->next == head) {
        head1 = head;
        head2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    head1 = head;
    head2 = slow->next;

    slow->next = head1;

    fast->next = head2;
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    insert(head, 10);
    insert(head, 4);
    insert(head, 9);

    Node *head1 = NULL, *head2 = NULL;

    splitList(head, head1, head2);

    cout << "First list: ";
    printList(head1);

    cout << "Second list: ";
    printList(head2);

    return 0;
}
