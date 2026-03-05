#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
int countNodes(struct Node* head){
    int count=0;
    struct Node* current=head;
    while (current!=NULL){
        count++;
        current=current->link;
    }
    return count;
}
void printNodes(struct Node* head){
    struct Node* current=head;
    while (current!=NULL){
        printf("Data of the node is: %d\n", current->data);
        current=current->link;
    }
}
int main(){
    struct Node* head = NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=3;
    head->link=NULL;

    struct Node* cur =NULL;
    cur=(struct Node*)malloc(sizeof(struct Node));
    cur->data=4;
    cur->link=NULL;
    head->link=cur;

    cur=NULL;
    cur=(struct Node*)malloc(sizeof(struct Node));
    cur->data=5;
    cur->link=NULL;
    head->link->link=cur;

    cur=NULL;
     cur=(struct Node*)malloc(sizeof(struct Node));
    cur->data=6;
    cur->link=NULL;
    head->link->link->link=cur;

    printf("The number of nodes in the linked list is: %d\n", countNodes(head));
    printNodes(head);
    
    return 0;
}