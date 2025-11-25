// 4. Given a doubly linked list having exactly one of the node pointing to a random node in the
// list, the task is  this random pointer in the doubly linked list, such that it points to
// the expected node.
// https://www.geeksforgeeks.o-the-random-pointer-in-doubly-linked-list/
// Input:

// Output:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* random;
    Node(int d) {
        data = d;
        next = prev = random = NULL;
    }
};

void correctRandomPointer(Node* head) {
    Node* curr = head;

    while (curr) {
        Node* expected;

        if (curr->next && curr->next->next)
            expected = curr->next->next;
        else
            expected = NULL;

        if (curr->random != expected) {
            curr->random = expected;   
            return;                
        }

        curr = curr->next;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Node " << temp->data << " | Random → ";
        if (temp->random) cout << temp->random->data;
        else cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Creating example
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;


    head->random = n3;     
    n2->random = n4;       
    n3->random = head;    
    n4->random = NULL;

    cout << "Before correction:\n";
    printList(head);

    correctRandomPointer(head);

    cout << "\nAfter correction:\n";
    printList(head);

    return 0;
}
