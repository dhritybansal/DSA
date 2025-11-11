// 3. Maximum Sum Combination
// You are given two integer arrays a[ ] and b[ ] of equal size. A sum combination is formed by adding
// one element from a[ ] and one from b[ ], using each index pair (i, j) at most once. Return the
// top k maximum sum combinations, sorted in non-increasing order.

// (Link:https://www.geeksforgeeks.org/problems/maximum-sum-
// combination/1?page=2&category=Sorting&sortBy=submissions)

// Example 1:
// Input: a[] = [3, 2], b[] = [1, 4], k = 2
// Output: [7, 6]
// Explanation: Possible sums: 3 + 1 = 4, 3
// + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums
// are 7 and 6.

// Example 2:
// Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
// Output: [10, 9, 9]
// Explanation: The top 3 maximum possible
// sums are : 4 + 6 = 10, 3 + 6 = 9, and 4+5=9

// Time Complexity: O(n log n) 
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> node; // (sum, (i, j))

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n), b(n);
    cout << "Enter elements of array a: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "Enter elements of array b: ";
    for (int i = 0; i < n; i++) cin >> b[i];

    cout << "Enter value of k: ";
    cin >> k;

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    priority_queue<node> maxHeap;

    set<pair<int, int>> visited;

    maxHeap.push({a[0] + b[0], {0, 0}});
    visited.insert({0, 0});

    vector<int> result;

    while (k-- && !maxHeap.empty()) {
        node current = maxHeap.top();
        maxHeap.pop();

        int sum = current.first;
        int i = current.second.first;
        int j = current.second.second;

        result.push_back(sum);

        if (i + 1 < n && !visited.count({i + 1, j})) {
            maxHeap.push({a[i + 1] + b[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }
        if (j + 1 < n && !visited.count({i, j + 1})) {
            maxHeap.push({a[i] + b[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }

    cout << "\nTop Maximum Sum Combinations: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
