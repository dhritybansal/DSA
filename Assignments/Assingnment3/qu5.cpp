#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;
int eval(string &s){
stack<int>st;
for(auto it:s){
    if(isdigit(it)){
        st.push(it - '0'); 

    }
    else{
        int val2=st.top();
        st.pop();
        int val1=st.top();
        st.pop();
           switch(it) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp = "345*+";
    cout << "Postfix Expression: " << exp << endl;
    cout << "Evaluated Result: " << eval(exp) << endl;
    return 0;
}