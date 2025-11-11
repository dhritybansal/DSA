// 5. Maximum Ice Cream Bars
// It is a sweltering summer day, and a boy wants to buy some ice cream bars.
// At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the
// price of the ith ice cream bar in coins. The boy initially has coins to spend, and he wants to buy as
// many ice cream bars as possible.
// Note: The boy can buy the ice cream bars in any order.
// Return the maximum number of ice cream bars the boy can buy with coins.
// You must solve the problem by counting sort.

// (Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=problem-list-
// v2&envId=sorting)

// Example 1:
// Input: costs = [1,3,2,4,1], coins
// = 7
// Output: 4
// Explanation: The boy can buy
// ice cream bars at indices
// 0,1,2,4 for a total price of 1 + 3
// + 2 + 1 = 7.

// Example 2:
// Input: costs = [10,6,8,7,7,8],
// coins = 5
// Output: 0
// Explanation: The boy cannot
// afford any of the ice cream
// bars.

// Example 3:
// Input: costs = [1,6,3,1,2,5],
// coins = 20
// Output: 6
// Explanation: The boy can buy
// all the ice cream bars for a total
// price of 1 + 6 + 3 + 1 + 2 + 5 = 18

// Time Complexity: O(n log n) 
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, coins;
    cout << "Enter number of ice creams: ";
    cin >> n;

    vector<int> costs(n);
    cout << "Enter costs: ";
    for (int i = 0; i < n; i++) cin >> costs[i];

    cout << "Enter available coins: ";
    cin >> coins;

    int maxCost = *max_element(costs.begin(), costs.end());

    vector<int> count(maxCost + 1, 0);
    for (int cost : costs)
        count[cost]++;

    int bars = 0;

    for (int cost = 1; cost <= maxCost && coins >= cost; cost++) {
        if (count[cost] == 0) continue;

        int canBuy = min(count[cost], coins / cost); 
        bars += canBuy;
        coins -= canBuy * cost;
    }

    cout << "\nMaximum Ice Cream Bars: " << bars << endl;
    return 0;
}
