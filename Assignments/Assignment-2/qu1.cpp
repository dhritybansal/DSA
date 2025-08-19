#include<iostream>
using namespace std;
int search(int arr[],int n,int x){
int left=0,right=n-1;
while(left<=right){
    int mid=(left+right)/2;
if(x>arr[mid]){
 left=mid+1;   
}
else if(x<arr[mid]){
    right=mid-1;
}
else{
cout<<x<<" is found at position"<<mid+1;
return mid+1;
}}
  cout << x << " not found" << endl;
    return -1;
}

int main(){
    int arr[]={1,4,2,6,5,9,8,19,17,14,24,26,28};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"enter the element you want to search for";
    cin>>x;
   search(arr,n,x);
}