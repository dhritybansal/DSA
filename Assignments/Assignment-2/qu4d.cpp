#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings ";
    cin >> n;
cin.ignore();
    string arr[100]; 
    cout << "Enter " << n << " strings" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) { 
               swap( arr[i] , arr[j]);
            }}}
            
    cout << "\n alphabetical order\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;}
}