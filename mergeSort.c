#include <stdio.h>
#include <stdlib.h>
#define arraySize 10
int temp[arraySize];

void inputUnsorted(int arr[])
{
    printf("\nReading Array\n\n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void merge(int arr[], int temp[], int l, int m, int h)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m)
    {
        temp[k++] = arr[i++];
    }

    while (j <= h)
    {
        temp[k++] = arr[j++];
    }

    for (i = l; i <= h; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int h)
{
    int m;

    if (l < h)
    {
        m = (l + h) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, temp, l, m, h);
    }
}

void displayArray(int arr[])
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("\t%d", arr[i]);
    }
}

int main()
{
    int arr[arraySize];

    inputUnsorted(arr);
    printf("\nUnSorted Array is: ");
    displayArray(arr);
    mergeSort(arr, 0, arraySize - 1);
    printf("\nSorted Array is: ");
    displayArray(arr);
    return 0;
}
