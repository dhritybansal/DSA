#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isVowel(char it) {
     char ch = tolower(it);
 if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
return true;
   else return false;
}

int main(){
    string str="hello my name is dhrity";
    string result = "";
    
    for(char it : str) {
        if(!isVowel(it))
            result += it;
    }
    
    cout<<"reverse string is "<<str;}