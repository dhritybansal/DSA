// 1. Given an array A, find the nearest smaller element for every element A[i] in the array such that the
// element has an index smaller than i.#include <iostream>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int>nearsmall(vector<int>&arr){
    stack<int>st;
    vector<int>result(arr.size(),-1);
for(int i=0;i<arr.size();i++){
    while(!st.empty()&&st.top()>=arr[i]){
        st.pop();
    }
    if(!st.empty()){
        result[i]=st.top();
    }
st.push(arr[i]);
}
return result;
}
int main(){
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nearsmall(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0; 
}