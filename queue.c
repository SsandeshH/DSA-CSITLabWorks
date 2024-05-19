#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

struct Queue{
	int items[MAX];
	int forward;
	int backward;
};

void enqueue(struct Queue *q);
void dequeue(struct Queue *q);
void display(struct Queue *q);

int main(){
	struct Queue q1;
	int choice;
	q1.forward=0;
	q1.backward=-1;
	
	while(1){
	
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nChoose: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			enqueue(&q1);
			break;
		case 2:
			dequeue(&q1);
			break;
		case 3:
			display(&q1);
			break;
		case 4:
			exit(-1);
			break;
		default:
			printf("\nChoose between 1,2,3 and 4\n");

			break;
	}
}
	return 0;
}
void enqueue(struct Queue *q){
	if(q->backward==MAX-1){
		printf("Queue is full\n");
		
	}else{
		int elt;
		printf("Enter an element: ");
		scanf("%d",&elt);
		q->backward++;
		q->items[q->backward]=elt;
	}
}

void dequeue(struct Queue *q){
	if(q->backward < q->forward){
		printf("Queue is empty\n");
	}else{
		printf("Dequeued item is %d\n",q->items[q->forward]);
		q->forward++;
	}
}

void display(struct Queue *q){
	if(q->backward<q->forward){
		printf("Queue is empty\n");
	}else{
		printf("\nItems are: ")
		for(int i=q->forward;i<=q->backward;i++){
			printf("%d\t",q->items[i]);
		}
		printf("\n");
	}
}

