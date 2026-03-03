#include <stdio.h>
#include <string.h>

// Selection Sort Function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// Pattern Matching Function
void matchPattern(char T[], char P[], int indices[], int *count) {
    int n = strlen(T), m = strlen(P);
    int found = 0;

    for (int i = 0; i <= n - m; i++) {
        int match = 1;
        for (int j = 0; j < m; j++) {
            if (T[i+j] != P[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            indices[(*count)++] = i;
            found = 1;
        }
    }

    if (!found) {
        printf("No match found for pattern \"%s\"\n", P);
    }
}

int main() {
    char T[] = "aabcabaacba";
    char P1[] = "ab";
    char P2[] = "ba";
    char P3[] = "cb";
    int indices[20], count = 0;

    int choice;
    printf("Enter pattern choice (1=ab, 2=ba, 3=cb): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            matchPattern(T, P1, indices, &count);
            break;
        case 2:
            matchPattern(T, P2, indices, &count);
            break;
        case 3:
            matchPattern(T, P3, indices, &count);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    // Sort indices using Selection Sort
    if (count > 0) {
        selectionSort(indices, count);

        // Print result
        printf("Sorted indices: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", indices[i]);
        }
        printf("\n");
    }

    return 0;
}
