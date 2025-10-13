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

node *rotateRight(node *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;
    node *temp = head;
    int cnt = 1;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    temp->next = head;
    if (k % cnt == 0)
        return head;
    int len = cnt - (k % cnt);
    temp = head;
    for (int i = 0; i < len - 1; i++)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
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
    vector<int> arr = {10,20,30,40,50,60,70,80,90};
    int k = 3;
    node *head = convertArr(arr);
    printlist(rotateRight(head, k));
    return 0;
}