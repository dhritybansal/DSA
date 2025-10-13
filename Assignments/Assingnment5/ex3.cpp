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
node* remove(node *head) {
   unordered_map< node *,int>mpp;
   node* prev=NULL;
  node *temp=head;
   while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){  
                  prev->next=NULL; 
                  return head;     
        }else{
            mpp[temp]=1; 
            prev=temp;               
            temp=temp->next;
        }
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
node* intersect=new node(9);
node* newnode=new node(4);
newnode->next=new node(5);
newnode->next->next=intersect;
intersect->next=new node(7);
intersect->next->next=new node(8);
intersect->next->next->next=intersect;

printlist(remove(newnode));
return 0;
}