#include <iostream>
#include <vector>
#include <string>
using namespace std;

void anagram(string s1, string s2) {
    if (s1.size() != s2.size()) {
        cout << "Not anagram" << endl;
        return;
    }

    vector<int> freq(26, 0); 

    for (char c : s1) freq[c - 'a']++;
    for (char c : s2) freq[c - 'a']--;

    for (int x : freq) {
        if (x != 0) {
            cout << "Not anagram" << endl;
            return;
        }
    }
    cout << "Yes, it is anagram" << endl;
}

int main() {
    string s1 = "listen";
    string s2 = "silent";
    anagram(s1, s2);
}
