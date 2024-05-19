#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct Stack{
	int item[MAX];
	int top;
};
void push(struct Stack *s);
void pop(struct Stack *s);
void display(struct Stack *s);

int main(){
	struct Stack S1;
	S1.top=-1;
	int choice;
	while(1){
	 printf("\nChoose:\n1.Push\n2.PoP\n3.Display\n4.Exit\nEnter: ");
	 scanf("%d",&choice);

	 switch(choice){
	 	case 1:
	 		push(&S1);
	 		break;
		case 2:
			pop(&S1);
			break;	 	
	 	case 3:
	 		display(&S1);
	 		break;
	 	case 4:
	 		exit(-1);
	 		break;
	 	default:
	 		printf("Enter only 1,2,3 or 4\n");
	 }
	}
	 return 0;
}

void push(struct Stack *s){

	int elt;

	if(s->top==MAX){
		printf("Stack Overflow\n");
		
	}else{
		printf("\nEnter an element to push: ");
		scanf("%d",&elt);
		s->top++;
		s->item[s->top]=elt;
		
	}
}

void pop(struct Stack *s){
	if(s->top==-1){
		printf("Stack underflow, cant pop any element\n");
	}else{
		printf("The popped element is %d\n",s->item[s->top]);
		s->top--;
	}
}

void display(struct Stack *s){
	if(s->top==-1){
		printf("\nStack Empty\n");
	}else{
	
	printf("The elements of the stack is ");
	for(int i=0;i<=s->top;i++){
		printf("%d  ",s->item[i]);
		}
		printf("\n");
	}
}
