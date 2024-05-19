#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *next;
} node;

int main()
{
node *top = NULL;
    int ch;
   
    printf("\nChoose your option below from below menu\n1. PUSH\n2. POP\n3. Display\n4. Exit\n");
    do
    {
        printf("\nYour Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            display(&top);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nPlease choose any number within the menu, TRY AGAIN!!!!");
        }
    } while (ch != 0);
    return 0;
}


void push(node **top){
    int num;
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("\nEnter the Number: ");
    scanf("%d",&num);
    temp->data = num;
    temp->next = NULL;
    if(*top==NULL){
            *top = temp;
    }else{
        temp->next = *top;
        *top = temp;
    }
}

void pop(node **top){
    node *temp;
    temp = *top;
    if(*top==NULL){
        printf("\nStack UnderFlow");
    }else{
        printf("\nThe Poped Item is %d",temp->data);
        *top = temp->next;
    }
    free(temp);
}

void display(node **top){
    node *temp;
    temp=*top;

        if(*top==NULL){
        printf("\nStack UnderFlow");
    }else{
        printf("\nThe Data in Stack is: ");
        while(temp!=NULL){
            printf("\t%d",temp->data);
            temp = temp->next;
        }
    }
    free(temp);
}
