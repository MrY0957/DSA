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
    struct Node* ptr1 =NULL;
    ptr1=(struct Node*)malloc(sizeof(struct Node));
    ptr1->data=3;
    ptr1->link=NULL;
    
    struct Node* ptr2 =NULL;
    ptr2=(struct Node*)malloc(sizeof(struct Node));
    ptr2->data=4;
    ptr2->link=NULL;
    ptr1->link=ptr2;
    
    linkedListTraversal(ptr1);
    return 0;
}