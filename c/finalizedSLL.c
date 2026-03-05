#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

// Insert node at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->link = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

// Count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->link;
    }
    return count;
}

// Print nodes like array
void printNodesAsArray(struct Node* head) {
    struct Node* current = head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->link != NULL) {
            printf(", ");
        }
        current = current->link;
    }
    printf("]\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("\nThe number of nodes: %d\n", countNodes(head));
    printf("Linked list as array: ");
    printNodesAsArray(head);

    return 0;
}