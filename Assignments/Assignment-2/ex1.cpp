#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
int diff(vector<int>& arr,int k){
    int n=arr.size();
    int count=0;
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
    if(i<j){
        if(abs(arr[i]-arr[j])==k){
        count++;}}}}
return count;
}
int main(){
      vector<int> arr = {1, 4, 1, 4, 5};
    int k = 3;
cout<<"total no of pairs are"<<endl<<diff(arr,k)<<endl;
return 0;
}
