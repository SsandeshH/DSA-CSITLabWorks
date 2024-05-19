#include <stdio.h>
#include <stdlib.h>
void inputUnsorted(int arr[], int n)
{
    printf("\nReading Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    int temp, i, j;
    inputUnsorted(arr, n);
    printf("\nThe unsorted array is: ");
    displayArray(arr, n);
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
    printf("\nThe sorted array using Bubble Sort is: ");
    displayArray(arr, n);
}

void selectionSort(int arr[], int n)
{
    int temp, i, j;
    inputUnsorted(arr, n);
    printf("\nThe unsorted array is: ");
    displayArray(arr, n);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nThe sorted array using Selection Sort is: ");
    displayArray(arr, n);
}

void insertionSort(int arr[], int n)
{
    int temp, i, j;
    inputUnsorted(arr, n);
    printf("\nThe unsorted array is: ");
    displayArray(arr, n);
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
    printf("\nThe sorted array using Insertion Sort is: ");
    displayArray(arr, n);
}

void shellSort(int arr[], int n)
{
    inputUnsorted(arr, n);
    printf("\nThe unsorted array is: ");
    displayArray(arr, n);
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    printf("\nThe sorted array using Bubble Sort is: ");
    displayArray(arr, n);
}

int main()
{
    int ch;

    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Shell Sort\n5. Exit\n");
    int n;
    int arr[100];
    do
    {
        printf("\n\nEnter choice: ");
        scanf("%d", &ch);
        printf("\nEnter number of data you wanna enter: ");
        scanf("%d", &n);
        switch (ch)
        {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        case 4:
            shellSort(arr, n);
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("\nPlease enter appropriate option");
        }
    } while (ch != 0);
    return 0;
}
