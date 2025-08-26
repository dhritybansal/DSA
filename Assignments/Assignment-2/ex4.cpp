#include<iostream>
using namespace std;
void sort(vector<int>& arr){
int n=arr.size();
int left=0,right=n-1,mid=0;
while(mid<=right){
    if (arr[mid]==0){
        swap(arr[left],arr[mid]);
        left++;
        mid++;
    }
else if(arr[mid]==1){
  mid++;
}
else {
       swap(arr[mid],arr[right]);
       right--;}}}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    
   sort(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}