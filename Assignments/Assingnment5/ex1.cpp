
// 1. Find the intersection node of two singly linked lists that merge into a Y-shaped structure.
// The lists may vary in length and have distinct nodes at the beginning, but from the point of
// intersection onward, they share the same sequence of nodes. The task is to identify the first
// common node where the two lists converge. If the two linked lists have no intersection at all,
// return null.
// TC = O(m + n)
// SC = O(1)
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *next;

public:
    node(int d, node *n)
    {
        data = d;
        next = n;
    }
    node(int d)
    {
        data = d;
        next = nullptr;
    }
};

node *convertArr(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *mover = head;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
node *getIntersectionNode(node *headA, node *headB)
{
    if (!headA || !headB)
        return NULL;

    node *p1 = headA;
    node *p2 = headB;

    while (p1 != p2)
    {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }

    return p1;
}

void printlist(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    node *intersect = new node(8);
    intersect->next = new node(4);
    intersect->next->next = new node(5);

    // List A
    node *headA = new node(4);
    headA->next = new node(1);
    headA->next->next = intersect;

    // List B
    node *headB = new node(5);
    headB->next = new node(6);
    headB->next->next = intersect;

    node *res = getIntersectionNode(headA, headB);

    if (res)
        cout << "Intersection at node with value " << res->data << endl;
    else
        cout << "No intersection" << endl;
}
