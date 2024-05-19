#include<stdio.h>
#include<stdlib.h>

void inputArray(int arr[],int n){
    printf("\nREADING ARRAY\n");
    for(int i=0;i<n;i++){
        printf("Array[%d]: ",i);
        scanf("%d",&arr[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    int temp, i, j;
    inputArray(arr,n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int linearSearch(int arr[], int key, int n){
int i;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    if(i==n){
        return -1;
    }
}

int binarySearch(int arr[],int low, int high, int key){
     if(low > high){
        return -1;
    }else{
    int mid = (low+high)/2;
        if(arr[mid]==key){
        return mid;
        }else if(arr[mid]>key){
          binarySearch(arr,low,mid-1,key);
        }else{
           binarySearch(arr,mid+1,high,key);
        }
    }
}

    int main(){

        int n,ch,key,ans;
       
                    printf("\nChoose Appropriate Option.\n1. Linear Search\n2. Binary Search\n3. Exit");
        do{
            printf("\n\nEnter your Choice: ");
            scanf("%d",&ch);
            printf("\nEnter no. of array you wanna enter: ");
            scanf("%d",&n);
            int arr[n];
            switch(ch){
        case 1:
            inputArray(arr,n);
            printf("\nEnter the KEY Element: ");
            scanf("%d",&key);
            ans = linearSearch(arr,key,n);
            if(ans==-1)
                printf("\nElement Not Found");
            else
            printf("\nThe Element %d was found on index %d",key,ans);
            break;
        case 2:
            bubbleSort(arr,n);
            printf("\nEnter the KEY Element: ");
            scanf("%d",&key);
            ans = binarySearch(arr,0,n-1,key);
            if(ans==-1)
                printf("\nElement Not Found");
            else
            printf("\nThe Element %d was found on index %d",key,ans);
            break;
        case 3:
            exit(-1);
            break;
        default:
            printf("\nChoose Correct Option");
            }
        }while(ch!=0);
    return 0;
    }

