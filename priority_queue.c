#include<stdio.h>
#include<limits.h>

struct Item{
    int value;
    int priority_value;
};

int count=-1;
struct Item pq[1000];

int main(){

int ch,val,pr;
    printf("\nEnter the number mentioned below to use the operation");
    printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit");
    do{
        printf("\nYour Choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\nEnter the value you want to enqueue: ");
            scanf("%d",&val);
            printf("\nEnter the value priority: ");
            scanf("%d",&pr);
            enqueue(val,pr);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display_ind();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("\nPlease choose appropriate number from the menu, TRY AGAIN!!!");
        }
    }while(ch!=0);
    return 0;
}

void enqueue(int val, int priority_val){
    count++;
    pq[count].value=val;
    pq[count].priority_value=priority_val;
}

void dequeue(){
    int ind = peek();
    printf("\nThe Dequeued value with highest priority is %d and it's priority is %d",pq[ind].value,pq[ind].priority_value);
    for(int i=ind;i<=count;i++){
        pq[i]=pq[i+1];
        count--;
    }
}

int peek(){
    int highest_priority = INT_MIN;
    int ind = -1;
    for(int i=0;i<=count;i++){
        if(highest_priority==pq[i].priority_value&&ind>-1&&pq[ind].value<pq[i].value){
            highest_priority = pq[i].priority_value;
            ind = i;
        }else if(highest_priority<pq[i].priority_value){
            highest_priority = pq[i].priority_value;
            ind = i;
        }
    }
    return ind;
}

void display(){
    for(int i=0;i<=count;i++){
        printf("\n(Value, Priority): (%d,%d)",pq[i].value,pq[i].priority_value);
    }
}

void display_ind(){
    int ind = peek();
    printf("\nThe index where the highest priority is INDEX = %d",ind);
}
