#include <stdio.h>

// Binary Search Function
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // not found
}

int main() {
    int arr[20] = {3, 7, 2, 4, 8, 1, 9};
    int n = 7;

    // Operation 1: Insert 6 before 2
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) { pos = i; break; }
    }
    if (pos != -1) {
        for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
        arr[pos] = 6;
        n++;
    }

    // Operation 2: Delete 1
    pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) { pos = i; break; }
    }
    if (pos != -1) {
        for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
        n--;
    }

    // Operation 3: Insert 5 before 1
    pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) { pos = i; break; }
    }
    if (pos != -1) {
        for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
        arr[pos] = 5;
        n++;
    } else {
        printf("Element 1 not found, skipping insert of 5.\n");
    }

    // Sort array for binary search
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Binary search for 8
    int index = binarySearch(arr, n, 8);

    // Print result
    printf("Final sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    if (index != -1)
        printf("Index of 8: %d\n", index);
    else
        printf("Element 8 not found.\n");

    return 0;
}
