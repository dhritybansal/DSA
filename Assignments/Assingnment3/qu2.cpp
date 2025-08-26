#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 100 
class Stack {
 string s;

public:
    Stack(string s) {
        this->s = s;
    }
   stack<char>st;
 void pushString() {
        for (char c : s) {
            st.push(c);
         } }
    void reverseString() {
        cout << "Reversed string: ";
        while (!st.empty()) {
            cout << st.top(); 
            st.pop();    
        }
        cout << endl;
    }
};
int main(){
    string s="dataStructures";
    int n=s.size();
    Stack s1(s);
     s1.pushString(); 
    s1.reverseString();
}