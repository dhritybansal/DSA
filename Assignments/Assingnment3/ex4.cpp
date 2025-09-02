// Given an array of integers temperatures represents the daily temperatures, return an
// array answer such that answer[i] is the number of days you have to wait after the ith day to get a
// warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreat(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, 0);
    stack<int> st; 

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top() - i;
        }
        st.push(i);
    }
    return result;
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextGreat(arr);

    for (int x : res) {
        cout << x << " ";
    }
    return 0;
}