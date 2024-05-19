#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int data;
    struct Queue *next;
}node;

int main(){
    node *front = NULL;
    node *rear = NULL;
    int ch;

    printf("\nChoose an option from the menu below\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
    do{
    printf("\nYour choice: ");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        enqueue(&front,&rear);
        break;
    case 2:
        dequeue(&front);
        break;
    case 3:
        display(&front);
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("\nSorry the Option you chose is wrong, please TRY AGAIN!!!");
    }
    }while(ch!=0);
return 0;
}

void enqueue(node **front, node **rear){
    node *temp;
    int num;
    temp = (node *)malloc(sizeof(node));
    printf("\nEnter the Number: ");
    scanf("%d",&num);
    temp->data = num;
    temp->next = NULL;
    if(*front == NULL){
        *rear = temp;
        *front = temp;
    }else{
        (*rear)->next = temp;
        *rear = temp;

    }
}

void dequeue(node **front){
    node *temp;
    temp = *front;
    if(*front == NULL){
        printf("\nQueue UnderFlow");
    }else{

            printf("\nThe Dequeued Element is %d",temp->data);
            *front = temp->next;

    }
    free(temp);
}

void display(node **front){
    node *temp;
    temp = *front;
    if(*front == NULL){
        printf("\nQueue UnderFlow");
    }else{
        printf("\nThe Data in Queue is: ");
        while(temp!=NULL){
            printf("\t%d",temp->data);
            temp = temp->next;
        }
    }
    free(temp);
}
