#include <stdio.h>
#include <string.h>

void matchPattern(char T[], char P[], int indices[], int *count) {
    int n = strlen(T), m = strlen(P);
    int found = 0; // track if any match found

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
    char P1[] = "bca";
    char P2[] = "ba";
    char P3[] = "aca";
    int indices[20], count = 0;

    int choice;
    printf("Enter pattern choice (1=bca, 2=ba, 3=aca): ");
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

    // Output
    if (count > 0) {
        printf("Found indices: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", indices[i]);
        }
        printf("\n");
    }

    return 0;
}
