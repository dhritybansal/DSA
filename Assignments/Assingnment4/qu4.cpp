#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    string nonrepeating(string &s) {
        queue<char> q;                    
        unordered_map<char, int> count;    
        string res = "";                   

        for (char ch : s) {
            count[ch]++;      
            q.push(ch);       

            while (!q.empty() && count[q.front()] > 1) {
                q.pop();
            }

            if (q.empty()) {
                res += '-1';
            } else {
                res += q.front();
            }
        }
        return res;
    }
};

int main() {
    string s = "aabc";
    Solution obj;
    cout << obj.nonrepeating(s) << endl;  
    return 0;
}
