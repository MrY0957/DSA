#include <stdio.h>

// Linear Search Function
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i; // found
    }
    return -1; // not found
}

int main() {
    int arr[20] = {3, 7, 2, 4, 8, 1, 9};
    int n = 7;

    // Operation 1: Insert 5 before 7
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 7) { pos = i; break; }
    }
    if (pos != -1) {
        for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
        arr[pos] = 5;
        n++;
    }

    // Operation 2: Delete 4
    pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 4) { pos = i; break; }
    }
    if (pos != -1) {
        for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
        n--;
    }

    // Operation 3: Insert 4 before 1
    pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) { pos = i; break; }
    }
    if (pos != -1) {
        for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
        arr[pos] = 4;
        n++;
    } else {
        printf("Element 1 not found, skipping insert of 4.\n");
    }

    // Linear Search for 8
    int index = linearSearch(arr, n, 8);

    // Print final array
    printf("Final array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    if (index != -1)
        printf("Index of 8: %d\n", index);
    else
        printf("Element 8 not found.\n");

    return 0;
}
