// Develop a menu driven program for the following operations of on a Circular as well
// as a Doubly Linked List.
// (a) Insertion anywhere in the linked list (As a first node, as a last node, and
// after/before a specific node).
// (b) Deletion of a specific node, say 'Delete node 60'. That mean the node to be
// deleted may appear as a head node, last node or a node in between.
// (c) Search for a node.
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
    node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

node *insertHead(node *tail, int val)
{
    node *newnode = new node(val);
    if (!tail)
    {
        newnode->next = newnode;
        return newnode;
    }
    node *temp = tail->next;
    tail->next = newnode;
    newnode->next = temp;
    return tail;
}

node *insertTail(node *tail, int val)
{
    node *newnode = new node(val);
    if (!tail)
    {
        newnode->next = newnode;
        return newnode;
    }
    node *temp = tail->next;
    tail->next = newnode;
    newnode->next = temp;
    tail = newnode;
    return tail;
}
node *insertbefore(node *tail, node *elenode, int val)
{
    node *head = tail->next;
    node *newnode = new node(val);
    newnode->next = elenode;
    node *temp = head;
    while (temp->next != elenode)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return tail;
}
void insertAfter(node *tail, int key, int val)
{
    if (!tail)
        return;
    node *temp = tail->next;
    do
    {
        if (temp->data == key)
        {
            node *newnode = new node(val);
            newnode->next = temp->next;
            temp->next = newnode;
            if (temp == tail)
                tail = newnode;
            return;
        }
        temp = temp->next;
    } while (temp != tail->next);
    cout << "Key not found!\n";
}
node *deleteHead(node *tail)
{
    if (!tail)
        return nullptr;
    node *temp = tail->next;
    if (temp == tail)
    {
        delete tail;
        return NULL;
    }
    tail->next = tail->next->next;
    delete temp;
    return tail;
    ;
}

node *deleteTail(node *tail)
{
    if (!tail)
        return nullptr;
    node *head = tail->next;
    if (head == tail)
    {
        delete head;
        return NULL;
    }
    node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = head;
    delete tail;
    return temp;
}
node *deletenode(node *tail, node *elenode)
{
    if (!tail)
        return nullptr;
    node *head = tail->next;
    if (head == tail)
    {
        delete head;
        return NULL;
    }
    node *temp = head;
    while (temp->next != elenode)
    {
        temp = temp->next;
    }
    temp->next = elenode->next;
    delete elenode;
    return tail;
}
node *deleteNode(node *tail, int val)
{
    if (!tail)
        return nullptr;
    node *head = tail->next;
    node *temp = head;
    node *prev = tail;

    do
    {
        if (temp->data == val)
        {
            if (temp == head)
                return deleteHead(tail);
            if (temp == tail)
                return deleteTail(tail);
            prev->next = temp->next;
            delete temp;
            return tail;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    cout << "node " << val << " not found\n";
    return tail;
}
void search(node *tail, int val)
{
    if (!tail)
    {
        cout << "List empty\n";
        return;
    }
    node *temp = tail->next;
    do
    {
        if (temp->data == val)
        {
            cout << "Node " << val << " found\n";
            return;
        }
        temp = temp->next;
    } while (temp != tail->next);

    cout << "Node " << val << " not found\n";
}

int main()
{
    node *tail = nullptr;
    int choice, val, key;

    do
    {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert After node\n";
        cout << "4. Delete Head\n";
        cout << "5. Delete Tail\n";
        cout << "6. Delete Specific node\n";
        cout << "7. Search node\n";
        cout << "8. Display List\n";
        cout << "9. Insert Before";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            tail = insertHead(tail, val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            tail = insertTail(tail, val);
            break;
        case 3:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            insertAfter(tail, key, val);
            break;
        case 4:
            tail = deleteHead(tail);
            break;
        case 5:
            tail = deleteTail(tail);
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> val;
            tail = deleteNode(tail, val);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            search(tail, val);
            break;
        case 8:
            printList(tail);
            break;
        case 9:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            {
                node *temp = tail->next;
                do
                {
                    if (temp->data == key)
                    {
                        tail = insertbefore(tail, temp, val);
                        break;
                    }
                    temp = temp->next;
                } while (temp != tail->next);
            }
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}