#include<stdio.h>
#include<stdlib.h>

typedef struct Linked_list{
    int data;
    struct Linked_list *next;
}node;

int main(){
    node *head;
    head = NULL;
    int ch;
   
    printf("\n1. Add At the Beginning\n2. Add At the End\n3. Add At the Specified Position\n4. Delete From Beginning\n5. Delete from End\n6. Delete From Specified Position\n7. Display\n8. Exit\n");

do{
        printf("\nEnter the Choice: ");
scanf("%d",&ch);
    switch(ch){
    case 1:
        addAtBeg(&head);
        break;
    case 2:
        addAtEnd(&head);
        break;
    case 3:
        addAtPos(&head);
        break;
    case 4:
        delAtBeg(&head);
        break;
    case 5:
        delAtEnd(&head);
        break;
    case 6:
        delAtPos(&head);
        break;
    case 7:
        display(&head);
        break;
    case 8:
        exit(1);
        break;
    default:
        printf("\nPlease choose appropriate option");
    }
}while(ch!=0);
return 0;
}

void addAtBeg(node **head){
    node *temp;
    int num;
    printf("\nEnter a Number: ");
    scanf("%d",&num);
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
    }else{
        temp->next = *head;
        *head = temp;
    }
}

void addAtEnd(node **head){
    node *temp;
    int num;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;

    if(*head == NULL){
        *head = temp;
    }else{
        node *temp1;
        temp1 = *head;
        while(temp1->next!=NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

void addAtPos(node **head){
    node *temp;
    int num,pos;
    printf("\nEnter a number: ");
    scanf("%d",&num);

    printf("\nEnter the psoition: ");
    scanf("%d",&pos);

    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;

    if(*head == NULL){
        *head = temp;
    }else{
        pos--;
        node *temp1;
        temp1 = *head;
        while(pos!=1){
            temp1 = temp1->next;
            pos--;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

void delAtBeg(node **head){
    node *temp;
    if(*head == NULL){
        printf("\nLink doesn't exist");
    }else{
        temp = *head;
        *head = temp->next;
        printf("\nDeleted Item is %d",temp->data);
        free(temp);
    }
}

void delAtEnd(node **head){
    node *temp,*temp1;
    temp = *head;
       if(*head == NULL){
        printf("\nLink doesn't exist");
    }
    while(temp->next != NULL){
        temp1 = temp;
        temp = temp->next;
    }
        temp1->next = NULL;
        printf("\nDeleted Item is %d",temp->data);
        free(temp);
}

void delAtPos(node **head){
    node *temp,*temp1;
    temp = *head;
    int pos;
   if(*head == NULL){
        printf("\nLink doesn't exist");
    }
    printf("\nEnter the Position: ");
    scanf("%d",&pos);
    for(int i=1;i<pos;i++){
        temp1 = temp;
        temp = temp->next;
        temp1->next = temp->next;
        printf("\nDeleted Item is %d",temp->data);
        free(temp);
    }
}

void display(node **head){
    node *temp;
    temp = *head;
    printf("\nData in Singly Linked Lists: ");
    while(temp!=NULL){
        printf("\t%d",temp->data);
        temp = temp->next;
    }
}
