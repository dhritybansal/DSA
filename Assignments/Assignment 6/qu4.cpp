// //4. Write a program to check if a doubly linked list of characters is palindrome or not.

// TC=O(n)
//SC=O(1)
#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class DoublyList {
public:
    Node* head;

    DoublyList() {
        head = NULL;
    }

    void insert(char ch) {
        Node* newNode = new Node(ch);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    bool isPalindrome() {
        if (!head || !head->next) return true;

        // Get left pointer
        Node* left = head;

        // Get right pointer (go to tail)
        Node* right = head;
        while (right->next) right = right->next;

        // Compare both ends
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyList dl;

    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        dl.insert(ch);
    }

    if (dl.isPalindrome())
        cout << "True";
    else
        cout << "False";

    return 0;
}
