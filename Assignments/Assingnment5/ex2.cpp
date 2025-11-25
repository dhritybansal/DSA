//2. Given a linked list and a positive number K, reverse the nodes in groups of K. All the remaining
//nodes after //multiples of k should be left as it is.
#include <iostream>
#include <vector>
#include <unordered_map>
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
node *getknode(node *temp, int k)
{
    k -= 1;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}
node *reverse(node *head)
{
    node *temp = head;
    node *prev = NULL;

    while (temp != NULL)
    {
        node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
node *reverseKGroup(node *head, int k)
{
    node *temp = head;
    node *prevlast = NULL;
    while (temp != NULL)
    {
        node *knode = getknode(temp, k);
        if (knode == NULL)
        { // if size of group is less than k
            if (prevlast)
                prevlast->next = temp;
            break;
        }
        node *nextnode = knode->next;
        knode->next = NULL;
        reverse(temp);
        if (temp == head)
        {
            head = knode;
        }
        else
        {
            prevlast->next = knode;
        }
        prevlast = temp;
        temp = nextnode;
    }
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
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90,};
    int k = 3;
    node *head = convertArr(arr);
    printlist(reverseKGroup(head, k));
    return 0;
}