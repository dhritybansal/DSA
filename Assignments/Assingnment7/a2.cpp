// 2. Top K Frequent in Array
// Given a non-empty integer array arr[ ] of size n, find the top k elements which have the highest
// frequency in the array. Note: If two numbers have the same frequencies, then the larger
// number should be given more preference. (Link:https://www.geeksforgeeks.org/problems/top-k-
// frequent-elements-in-array/1?page=2&category=Sorting&sortBy=submissions)

// Example 1:
// Input: arr[] = [3, 1, 4, 4, 5, 2, 6, 1], k = 2
// Output: [4, 1]
// Explanation: Frequency of 4 is 2 and
// frequency of 1 is 2, these two have the
// maximum frequency and 4 is larger than 1.

// Example 2:
// Input: arr[] = [7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9],
// k = 4
// Output: [5, 11, 7, 10]
// Explanation: Frequency of 5 is 3, frequency
// of 11 is 2, frequency of 7 is 2, frequency of
// 10 is 1.

// TC: O(n log n) — because of sorting
// SC: O(n) — for map and vector


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second != b.second)
        return a.second > b.second;  
    else
        return a.first > b.first;   }

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter value of k: ";
    cin >> k;

    unordered_map<int, int> freq;
    for (int num : arr)
        freq[num]++;

    vector<pair<int, int>> freqVec(freq.begin(), freq.end());

    sort(freqVec.begin(), freqVec.end(), compare);

    cout << "\nTop " << k << " Frequent Elements: ";
    for (int i = 0; i < k && i < freqVec.size(); i++)
        cout << freqVec[i].first << " ";
    cout << endl;

    return 0;
}
