#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char lower(char *it) {
     char ch = tolower(*it);
 return ch;
}
int main(){
    string s;
    cout<<"enter string";
    getline(cin,s);
    int n=s.size();
for(int i=0;i<n;i++){
 s[i]=lower(&s[i]);
}
cout<<endl<<s;
}