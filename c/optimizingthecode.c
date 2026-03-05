#include<stdio.h>
#include<stdlib.h>  
struct Node {
    int data;
    struct Node* link;
};
void linkedListTraversal(struct Node* ptr){
    while (ptr!=NULL){
        printf("Data of the node is: %d\n", ptr->data);
        ptr=ptr->link;
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

    linkedListTraversal(head);
    return 0;
}