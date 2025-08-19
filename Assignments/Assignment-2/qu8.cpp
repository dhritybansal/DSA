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
        bool dup=false;
          for(int j=i+1;j<n;j++){
if(arr[i]==arr[j]){
 dup=true;
    break;
}}
if(dup==false)
cnt++;

      }
      cout<<"unique elements"<<cnt;
}