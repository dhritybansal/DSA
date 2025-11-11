
// 2. A slightly improved selection sort – We know that selection sort algorithm takes the minimum on
// every pass on the array, and place it at its correct position. The idea is to take also the maximum on
// every pass and place it at its correct position. So in every pass, we keep track of both maximum and
// minimum and array becomes sorted from both ends. Implement this logic.

// Time Complexity: O(n²) 
// Space Complexity: O(1)

#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while(left < right) {
        int minIndex = left;
        int maxIndex = right;

        // Find min and max in current range
        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[minIndex])
                minIndex = i;
            if(arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Swap min element with leftmost element
        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        // If max element was at left, its position changed due to above swap
        if(maxIndex == left)
            maxIndex = minIndex;

        // Swap max element with rightmost element
        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    improvedSelectionSort(arr, n);

    printf("\nSorted Array (Improved Selection Sort): ");
    printArray(arr, n);
    return 0;
}
