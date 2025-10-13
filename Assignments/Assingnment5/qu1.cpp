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

node *insertBeg(node *head)
{
    int k;
    cout << "enter the element u want to insert";
    cin >> k;
    node *start = new node(k, head);
    return start;
}

node *insertEnd(node *head)
{
    int k;
    cout << "enter the element u want to insert";
    cin >> k;
    if (head == NULL)
        return new node(k, head);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *end = new node(k);
    temp->next = end;
    return head;
}

node *insertBeforeN(node *head)
{
    int el, val;
    cout << "enter the element and the value before which u want to insert the value";
    cin >> el >> val;
    if (head == NULL)
        return head;
    if (head->data == el)
    {
        return new node(val, head);
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == el)
        {
            node *newnode = new node(val, temp->next);
            temp->next = newnode;
            break;
        }
        else
            temp = temp->next;
    }
    return head;
}

node *insertAfterN(node *head)
{
    int el, val;
    cout << "enter the element and the value after which u want to insert the value";
    cin >> el >> val;
    if (head == NULL)
        return head;

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            node *newnode = new node(val, temp->next);
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

node *deleteHead(node *head)
{
    if (head == NULL)
        return head;
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

node *deleteTail(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;

    temp->next = NULL;

    return head;
}

node *deleteKey(node *head)
{
    int k;
    cout << "enter the element u want to delete";
    cin >> k;
    if (head == NULL)
        return head;
    int count = 0;
    while (head != nullptr && head->data == k)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    node *temp = head;
    node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            prev->next = prev->next->next;
            delete temp;
            temp = prev->next;
            count++;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "count is" << count;
    return head;
}

void search(node *head)
{
    int k;
    cout << "Enter the element you want to search for: ";
    cin >> k;

    int pos = 1;
    bool found = false;
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == k)
        {
            cout << k << " found at position " << pos << endl;
            found = true;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
    {
        cout << k << " not found in the list." << endl;
    }
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

    int choice;
    do
    {
        cout << "1 to insert at beginning" << endl;
        cout << "2  to insert at end" << endl;
        cout << "3 to insert before a node" << endl;
        cout << "4 to insert after a node" << endl;
        cout << "5 delete head" << endl;
        cout << "6 DELETE tail" << endl;
        cout << "7 delete a specific node" << endl;
        cout << "8 search for a node" << endl;
        cout << "9 to display all nodes" << endl;
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            head = insertBeg(head);
            break;
        case 2:
            head = insertEnd(head);
            break;
        case 3:
            head = insertBeforeN(head);
            break;
        case 4:
            head = insertAfterN(head);
            break;
        case 5:
            head = deleteHead(head);
            break;
        case 6:
            head = deleteTail(head);
            break;
        case 7:
            head = deleteKey(head);
            break;
        case 8:
            search(head);
            break;
        case 9:
            printlist(head);
            break;
        case 10:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 10);

    return 0;
}
