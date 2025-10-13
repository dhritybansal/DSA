// 3. Write a program to find the middle of a linked list.
// Input: 1->2->3->4->5
// Output: 3
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
node *middle(node *head)
{
    // if (head == NULL )
    //     return head;
    // node *temp = head;
    // int cnt = 0;
    // while (temp != NULL)
    // {
    //     cnt++;
    //     temp = temp->next;
    // }
    // int mid = (cnt / 2)+1;
    // temp = head;

    // for (int i = 1; i < mid; i++)
    // {
    //     temp = temp->next;
    // }
    // return temp;
    if (head == NULL)
        return head;
    node *fast = head;
    node *slow = head;
   
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;             
    }
    return slow;
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
    vector<int> arr = {1, 2, 3, 4, 5};
    node *head = convertArr(arr);

    cout << "Original List: ";
    printlist(head);

    node *midNode = middle(head);
    cout << "Middle element: " << midNode->data << endl;

    return 0;
}