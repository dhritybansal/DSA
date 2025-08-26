#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool parenth(string s){
    stack<char>st;
    for(char i:s){
if(i=='['||i=='('||i=='{'){
st.push(i);}
else {
    if(st.empty())
    return false;
char top =st.top();
st.pop();
if((top!='('&&i==')')||(top!='['&&i==']')||(top!='{'&&i=='}')){
    return false;}
}
} return(st.empty());
}

int main(){
    string s="{[()]}";
   cout<<s<< " " <<(parenth(s)?"balanced":"not balanced");
}