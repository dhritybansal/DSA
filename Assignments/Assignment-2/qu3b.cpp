#include <iostream>
using namespace std;

int Missing(int arr[], int n) {
    int low=0,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
  if(mid+1==arr[mid]){
low=mid+1;}
else 
high=mid-1;}
return low+1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6};
    int n = 6;
    cout << "Missing number is " << Missing(arr, n);
    return 0;
} 