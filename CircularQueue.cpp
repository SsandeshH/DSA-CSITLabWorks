#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
struct CQueue{
int data[MAX];
int front;
int rear;
};

void Enqueue(struct CQueue *cq);
void Dequeue(struct CQueue *cq);
void display(struct CQueue *cq);

int main(){
struct CQueue cq;

cq.front=MAX-1;
cq.rear=MAX-1;
int ch;

printf("\nChoose\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    while(1){
        printf("\nYour Choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            Enqueue(&cq);
            break;
        case 2:
            Dequeue(&cq);
            break;
        case 3:
            display(&cq);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nChoose 1,2,3 or 4 only");
        }
}


    return 0;
}
void Enqueue(struct CQueue *cq){
int elt;
printf("\nEnter a element to Enqueue:");
scanf("%d", &elt);
if((cq->rear+1)%MAX==cq->front){
        printf("\nQueue is full");
}else{
    cq->rear=(cq->rear+1)%MAX;
    cq->data[cq->rear]=elt;
	}
}

void Dequeue(struct CQueue *cq){
int elt;

if(cq->front==cq->rear){
        printf("\nDisplay is empty");
}else{
    cq->front=(cq->front+1)%MAX;
    printf("\n The dequeue element was %d",cq->data[cq->front]);
}
}

void display(struct CQueue *cq){
    int i;
if(cq->front==cq->rear){
    printf("\n Queue empty");

}else{

for(i=(cq->front+1)%MAX;i!=(cq->rear);i=(i+1)%MAX){
    printf("%d\t",cq->data[i]);
}

printf("%d",cq->data[i]);
}
}

