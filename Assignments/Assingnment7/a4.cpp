// 4. Sort even-placed in increasing and odd-placed in decreasing order
// We are given an array of n distinct numbers. The task is to sort all even-placed numbers in increasing

// and odd-placed numbers in decreasing order. The modified array should contain all sorted even-
// placed numbers followed by reverse sorted odd-placed numbers.

// Note that the first element is considered as even placed because of its index 0.

// Example 1:
// Input: arr[] = {0, 1, 2, 3, 4, 5, 6, 7}
// Output: arr[] = {0, 2, 4, 6, 7, 5, 3, 1}
// Explanation:
// Even-place elements : 0, 2, 4, 6
// Odd-place elements : 1, 3, 5, 7
// Even-place elements in increasing order :
// 0, 2, 4, 6
// Odd-Place elements in decreasing order :
// 7, 5, 3, 1

// Example 2:
// Input: arr[] = {3, 1, 2, 4, 5, 9, 13, 14, 12}
// Output: {2, 3, 5, 12, 13, 14, 9, 4, 1}
// Explanation:
// Even-place elements : 3, 2, 5, 13, 12
// Odd-place elements : 1, 4, 9, 14
// Even-place elements in increasing order :
// 2, 3, 5, 12, 13
// Odd-Place elements in decreasing order :
// 14, 9, 4, 1

// Time Complexity: O(n ) 
// Space Complexity: O(n)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> even, odd;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());

    vector<int> result;
    result.insert(result.end(), even.begin(), even.end());
    result.insert(result.end(), odd.begin(), odd.end());

    cout << "\nModified Array: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
