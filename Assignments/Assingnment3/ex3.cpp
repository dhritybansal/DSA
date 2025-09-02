//Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the
// array in order of their appearance in the array. Note: The Next Greater Element for an element x is
// the first greater element on the right side of x in the array. Elements for which no greater element
// exist, consider the next greater element as -1.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int>nextgreat(vector<int>&arr){
    stack<int>st;
    vector<int>result(arr.size(),-1);
for(int i=arr.size()-1;i>=0;i--){
    while(!st.empty()&&st.top()<=arr[i]){
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
    vector<int> res = nextgreat(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0; 
}