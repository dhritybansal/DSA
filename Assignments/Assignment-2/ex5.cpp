#include<iostream>
#include<vector>
using namespace std;
    void duplicateZeros(vector<int>& arr,int n) {
        for(int i=0;i<n;i++){
            if(arr[i]==2){
                int j=i;
                for(int k=n-1;k>j;k--){
                    arr[k]=arr[k-1];
                }
                 if(j+1 < n){
                arr[j+1]=2;
                i++;
            }}
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
int main(){
    vector<int> arr= {1,0,2,3,2,4,5,0};
  int n=arr.size();
 duplicateZeros(arr,n);
 return 0;
}