// 2. Write a program to count the number
// of occurrences of a given key in a singly linked
//  list and then delete all the occurrences.
//  Input: Linked List : 1->2->1->2->1->3->1 , key: 1
//  Output: Count: 4 , Updated Linked List: 2->2->3.
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
node* deleteKey(node* head, int k)
{
    if (head == NULL)
        return head;
    int count = 0;
    while (head != nullptr && head->data == k){
            node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
    node* temp = head;
    node* prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            prev->next = prev->next->next;
            delete temp;
            temp=prev->next;
             count++;
             
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }}
    
    cout<<"count is"<<count;
    return head;
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

    int key = 1;
    node* newHead = deleteKey(head, key);

    cout << "Updated List: ";
    printlist(newHead );

    return 0;
}