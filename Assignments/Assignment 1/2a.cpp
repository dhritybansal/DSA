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
    int a;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
a=j;
for(int k=a;k<n-1;k++){
    arr[k]=arr[k+1];
}
 n--;
j--;}}}
 for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}