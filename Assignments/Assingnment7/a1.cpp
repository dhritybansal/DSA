// //1. Majority Element
// Given an array nums of size n, return the majority element. The majority element is the element that
// appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// (Link:https://leetcode.com/problems/majority-element/description/?envType=problem-list-
// v2&envId=sorting)

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2


// Time Complexity: O(n) 
// Space Complexity: O(1)

#include <stdio.h>

int majorityElement(int nums[], int n) {
    int candidate = nums[0];
    int count = 1;

    for(int i = 1; i < n; i++) {
        if(nums[i] == candidate)
            count++;
        else
            count--;

        if(count == 0) {
            candidate = nums[i];
            count = 1;
        }
    }
    return candidate;
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int result = majorityElement(nums, n);
    printf("\nMajority Element: %d\n", result);

    return 0;
}
