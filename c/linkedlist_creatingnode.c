#include<stdio.h>
#include<stdlib.h>  
struct Node {
    int data;
    struct Node* link;
};

int main(){
    struct Node* head = NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=3;
    head->link=NULL;
    printf("Data of the node is: %d", head->data);
    return 0;
}
