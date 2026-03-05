#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
void count_nodes(struct Node* head){
        int count=0;
        if(head==NULL){
            printf("The linked list is empty");
            return;
        }
        struct Node* ptr=NULL;
        ptr=head;
        while(ptr!=NULL){
            count++;
            ptr=ptr->link;
        }
        printf("The number of nodes in the linked list is: %d", count);
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
    count_nodes(head);
    return 0;
}