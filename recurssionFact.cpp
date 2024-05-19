//recurssion lab1
#include<stdio.h>
#include<stdlib.h>

int fact(int a);
int fibo(int a);
int gcd(int a,int b);
int TOH(int a);
void hanoi(int n,char from,char to,char through);

int main(){
	int num,choice;

	printf("1.Factorial\n2.Fibonacci Sequence\n3.GCD\n4.Tower of Hanoi\n5.Exit");
	while(1){
		
	printf("\nEnter Your Choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter a number: ");
			scanf("%d",&num);
			printf("\nThe factorial of %d is %d",num,fact(num));
			break;	
		case 2:
            printf("\nEnter the number whose fibonacci sequence is to be found: ");
            scanf("%d",&num);
            printf("\nThe %d fibonacci Sequence is: ",num);
            for(int i=0;i<=num;i++){
                printf("%d\t",fibo(i));
            }
            printf("\n");
            break;
		case 3:
			int x,y;
			printf("\nEnter two numbers : ");
			scanf("%d%d",&x,&y);
			printf("\nThe GCD of %d and %d is %d",x,y,gcd(x,y));
			break;
		case 4:
			printf("\nEnter a number: ");
			scanf("%d",&num);
			hanoi(num,'S','D','C');
			
			break;
		case 5:
			exit(-1);
		default:
			printf("\nChoose from 1-5 only");
			
			
	}
}
	return 0;
}

int fact(int a){
	if(a==1){
		return a;
	}
	else{
		return a*fact(a-1);
	}
}

int fibo(int a){
	if(a==0||a==1){
		return a;
	}else{
	
		return (fibo(a-1)+fibo(a-2));
	}
}
int gcd(int a,int b){
	if(b!=0){
		return gcd(b,a%b);
	
	}else{
		return a;
	}
}
void hanoi(int n,char from,char to,char through){
	if(n==1){
		printf("Move disk 1 from %c to %c\n",from,to);
	}else{
		hanoi(n-1,from,through,to);
		printf("Move disk %d from %c to %c\n",n,from,to);
		hanoi(n-1,through,to,from);
	}
}