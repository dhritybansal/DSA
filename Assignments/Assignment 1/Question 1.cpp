#include<iostream>
using namespace std;
int arr[1000];
int n;

void  createArray(){
cout<<"enter size of array";
    cin>>n;
    cout<<"enter elements";
    for(int i=0;i<n;i++){
        cin>>arr[i];}
}

void displayArray(){
      if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insertElement(){
   int pos,val;
   cout<<"enter the position and value of element";
   cin>>pos>>val;
      if (pos < 1 || pos > n+1) {
        cout << "Invalid position!\n";
        return;
    }
for(int i=n-1;i>=pos-1;i--){
    arr[i+1]=arr[i];
}
arr[pos-1]=val;
  n++;
 for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
  
}

void deleteElement(){
    int pos;
   cout<<"enter the position  of element";
   cin>>pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
for(int i=pos-1;i<n;i++){
    arr[i]=arr[i+1];
}
 n--;
 for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void linearSearch(){
int key;
cout<<"enter value to search";
cin>>key;
bool flag=false;
for(int i=0;i<n;i++){
    if(arr[i]==key){
        cout<<"Found at position " << i+1 << endl;
        flag=true;
    }
}
if (flag==false) {
        cout << "Element not found.\n";
}}

int main(){
    int choice;
    do{
    cout<<"MENU"<<endl;
    cout<<"1 CREATE"<<endl;
    cout<<"2 DISPLAY"<<endl;
    cout<<"3 INSERT"<<endl;
    cout<<"4 DELETE"<<endl;
    cout<<"5 LINEAR SEARCH"<<endl;
    cout<<"6 EXIT"<<endl;
    cin>>choice;

switch(choice){
                case 1: createArray(); break;
                case 2: displayArray(); break;
                case 3: insertElement(); break;
                case 4: deleteElement(); break;
                case 5: linearSearch(); break;
                case 6: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice!\n";
    }}while (choice != 6);
    return 0;
}
