// Write a program to reverse a linked list.
// Input: 1->2->3->4->NULL
// Output: 4->3->2->1->NULL
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
node* reverse(node* head)
{

   node* prev = NULL;
    node* curr = head;
    while (curr != NULL) {
        node* next = curr->next; 
        curr->next = prev;         
        prev = curr;                
        curr = next;              
    }
    return prev; 
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
    vector<int> arr = {1, 2, 1, 2, 1, 3, 1};
    node *head = convertArr(arr);

    cout << "Original List: ";
    printlist(head);

   
    node* newHead = reverse(head);

    cout << "Updated List: ";
    printlist(newHead );

    return 0;
}