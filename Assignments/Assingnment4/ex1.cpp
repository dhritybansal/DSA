#include <iostream>
#include <stack>
using namespace std;

void generateBinary(int n) {
    for (int i = 1; i <= n; i++) {
        int num = i;
        stack<int> st;

        while (num > 0) {
            st.push(num % 2);
            num /= 2;
        }

        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << " ";
    }
}

int main() {
    int n = 5;
    generateBinary(n);
    return 0;
}
