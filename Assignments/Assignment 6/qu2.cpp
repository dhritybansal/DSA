#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *next;

public:
    node(int d = 0, node *n = nullptr)
    {
        data = d;
        next = n;
    }
};
node *convertArr(vector<int> arr)
{
    node *head = new node(arr[0]);
    node *temp = head;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        node *newnode = new node(arr[i]);
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;
    return temp;
}
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
int main()
{
    vector<int> arr = {20, 100, 40, 80, 60};
    node *tail = convertArr(arr);
    cout << "Circular Linked List: ";
    printList(tail);
    return 0;
}
