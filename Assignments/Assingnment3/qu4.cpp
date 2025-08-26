#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int prior(char c){
    if(c=='^')return 3;
    else if(c=='/'||c=='*')return 2;
      else if(c=='+'||c=='-')return 1;
      else return -1;
}
string infixtopostfix(string s){
    stack<char>st;
    vector<char>result;
    for(char i:s){
    if (isalnum(i)){
    result.push_back(i);}
    else if(i=='('){
        st.push(i);
    }
    else if(i==')'){
        while(!st.empty()&&st.top()!='('){
                 result.push_back(st.top());
                 st.pop();
        }
        st.pop();}
        else  {
            while(!st.empty()&& prior(st.top())>=prior(i)){
                  result.push_back(st.top());
                 st.pop();}
                 st.push(i);
        }}
          while(!st.empty()){
                 result.push_back(st.top());
                 st.pop();
    }
   string ans(result.begin(),result.end());
    return ans;
    }
    int main(){
        string s="a+b*(c^d-e)";
       cout<<s<< " "<<infixtopostfix(s);

    }