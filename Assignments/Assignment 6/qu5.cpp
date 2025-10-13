// 5. Write a program to check if a linked list is Circular Linked List or not.

// Example 1:

// Input:

// LinkedList: 2->4->6->7->5

// Output: True

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = nullptr;
    }
};
void printList(node *tail)
{
    if (!tail)
    {
        cout << "List is empty\n";
        return;
    }
    node *head = tail->next;
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << head->data << endl;
    cout << endl;
}

bool isCircular(node *tail)
{
    if (!tail)
        return false;
    return tail->next != nullptr;
}

int main()
{

    node *n1 = new node(2);
    node *n2 = new node(4);
    node *n3 = new node(6);
    node *n4 = new node(7);
    node *n5 = new node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1;

    node *tail = n5;
    printList(tail);
    if (isCircular(tail))
        cout << "True: It is a circular linked list.\n";
    else
        cout << "False: It is not a circular linked list.\n";

    return 0;
}
