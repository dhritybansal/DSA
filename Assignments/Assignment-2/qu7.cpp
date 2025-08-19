#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array";
    cin>>n;
    int arr[n];
    
    cout<<"enter elements of array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
      for(int i=0;i<n-1;i++){
     
          for(int j=i+1;j<n;j++){
if(i<j&&arr[i]>arr[j]){

cout<<"("<<arr[i]<<","<<arr[j]<<")";
cnt++;
}}
      }
      cout<<endl<<"total inversions pairs"<<cnt;
}