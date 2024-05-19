#include <stdio.h>
#include <stdlib.h>
#define arraySize 10
int temp[arraySize];

void inputArray(int arr[]) // input for array
{
    printf("Reading Array\n\n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[]) // display array
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("\t%d", arr[i]);
    }
}

void swap(int *a, int *b) // swapping functionx
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// merge Sort Function Starts

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

// merge Sort Function Ends

// quick Sort Function Starts

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pos = partition(arr, l, h);
        quickSort(arr, l, pos - 1);
        quickSort(arr, pos + 1, h);
    }
}

// quick Sort Function Ends

// heap Sort Function Starts

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// heapify Sort Function Ends

int main()
{

    printf("\nChoose Option From Below:\n1.Merge Sort\n2.Quick Sort\n3. Heap Sort\n4. Exit");
    int arr[arraySize], ch;

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
                inputArray(arr);
    printf("\nUnSorted Array is: ");
    displayArray(arr);
            mergeSort(arr, 0, arraySize - 1);
            printf("\nSorted Array Using Merge Sort is: \n");
            displayArray(arr);
            break;
        case 2:    inputArray(arr);
    printf("\nUnSorted Array is: ");
    displayArray(arr);

            quickSort(arr, 0, arraySize - 1);
            printf("\nSorted Array Using Quick Sort is: \n");
            displayArray(arr);
            break;
        case 3:
                inputArray(arr);
    printf("\nUnSorted Array is: ");
    displayArray(arr);
            heapSort(arr, arraySize);
            printf("\nSorted Array Using Heap Sort is: \n");
            displayArray(arr);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nPlease Choose Appropritate Option");
        }
    } while (ch != 0);

    return 0;
}

