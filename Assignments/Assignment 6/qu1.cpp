#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *next;
    node *back;

public:
    node(int d, node *n, node *b)
    {
        data = d;
        next = n;
        back = b;
    }
    node(int d)
    {
        data = d;
        next = nullptr;
        back = nullptr;
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
        temp->back = mover;
        mover = temp;
    }
    return head;
}

node *insertBeg(node *head)
{
    int k;
    cout << "enter the element u want to insert in beginning or before head";
    cin >> k;
    node *start = new node(k, head, nullptr);
    head->back = start;
    return start;
}

node *insertEnd(node *head)
{
    int k;
    cout << "enter the element u want to insert after tail";
    cin >> k;
    if (head == NULL)
        return new node(k);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *end = new node(k, nullptr, temp);
    temp->next = end;
    return head;
}

node *insertBeforeN(node *head)
{
    int el, val;
    cout << "enter the element and the value before which u want to insert the value";
    cin >> el >> val;
    if (head == NULL)
        return new node(val);

    if (head->data == el)
    {
        node *start = new node(val, head, nullptr);
        head->back = start;
        return start;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == el)
        {
            node *element = temp->next;
            node *newnode = new node(val, element, temp);
            temp->next = newnode;
            element->back = newnode;
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
        return new node(val);

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            node *element = temp->next;
            node *newnode = new node(val, element, temp);
            temp->next = newnode;
            if (element)
                element->back = newnode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

node *deleteHead(node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    node *temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

node *deleteTail(node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *tail = temp->back;
    tail->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

node *deleteKey(node *head)
{
    int k;
    cout << "enter the element u want to delete";
    cin >> k;

    if (head == NULL)
        return head;

    int count = 1;
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == k)
        {
            node *prev = temp->back;
            node *front = temp->next;
            if (prev == NULL && front == NULL)
            {
                return NULL;
            }
            else if (prev == NULL)
            {
                return deleteHead(head);
            }
            else if (front == NULL)
            {
                return deleteTail(head);
            }
            prev->next = temp->next;
            front->back = temp->back;
            temp->back = nullptr;
            temp->next = nullptr;
            delete temp;
            break;
        }

        count++;
        temp = temp->next;
    }

    cout << "pos of delted key  is" << count;
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
        cout << "Enter choice for dll: ";
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
