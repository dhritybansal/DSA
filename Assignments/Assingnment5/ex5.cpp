// 5. Given two polynomial numbers represented by two linked lists. The task is
//  to add these lists (meaning the coefficients with the same variable powers will be
//  added).
//  Input:
//  head1: [[5, 3], [4, 2], [2, 0]]
//  head2: [[5, 1], [-5, 0]]
//  Output: [[5, 3], [4, 2], [5, 1], [-3, 0]]
//  Explanation: head1 can be represented as 5x^3 + 4x^2 + 2 ,
//   head2 can be represented as 5x - 5, add both the polynomials to get
//    5x^3 + 4x^2 + 5x - 3
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node
{
    int coeff;
    int pow;
    node *next;

public:
    node(int d, int p)
    {
        coeff = d;
        pow = p;
        next = nullptr;
    }
};

node *insert(node *head, int coeff, int pow)
{
    node *newNode = new node(coeff, pow);
    if (!head)
        return newNode;

    node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

node *addPolynomial(node *head1, node *head2)
{
    node *dummy = new node(0, 0);
    node *temp = dummy;
    node *curr1 = head1, *curr2 = head2;
    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1->pow < curr2->pow)
        {
            temp->next = curr2;
            temp = curr2;
            curr2 = curr2->next;
        }
        else if (curr1->pow > curr2->pow)
        {
            temp->next = curr1;
            temp = curr1;
            curr1 = curr1->next;
        }
        else
        {
            curr1->coeff = curr1->coeff + curr2->coeff;
            temp->next = curr1;
            temp = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    if (curr1 != nullptr)
    {
        temp->next = curr1;
    }

    if (curr2 != NULL)
    {
        temp->next = curr2;
    }
    return dummy->next;
}
void printlist(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->coeff << "," << temp->pow << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // 1st polynomial: 5x^2+4x^1+2x^0
    node *head1 = new node(5, 2); 
    head1->next = new node(4, 1);
    head1->next->next = new node(2, 0);

    // 2nd polynomial: -5x^1-5x^0
    node *head2 = new node(-5, 1);
    head2->next = new node(-5, 0);

    node *head = addPolynomial(head1, head2);

    printlist(head);
}

// int main() {
//     int n1, n2;
//     cout << "Enter number of terms in 1st polynomial: ";
//     cin >> n1;

//     node* head1 = nullptr;
//     cout << "Enter coeff and power for " << n1 << " terms:\n";
//     for (int i = 0; i < n1; i++) {
//         int c, p;
//         cin >> c >> p;
//         head1 = insert(head1, c, p);
//     }

//     cout << "Enter number of terms in 2nd polynomial: ";
//     cin >> n2;

//     node* head2 = nullptr;
//     cout << "Enter coeff and power for " << n2 << " terms:\n";
//     for (int i = 0; i < n2; i++) {
//         int c, p;
//         cin >> c >> p;
//         head2 = insert(head2, c, p);
//     }

//     cout << "\n1st Polynomial: ";
//     printlist(head1);
//     cout << "2nd Polynomial: ";
//     printlist(head2);

//     node* result = addPolynomial(head1, head2);

//     cout << "\nResultant Polynomial: ";
//     printlist(result);

//     return 0;
// }