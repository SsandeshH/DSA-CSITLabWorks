#include <stdio.h>
#include <stdlib.h>

int hashIndex(int key, int m)
{
    return (key % m);
}

void collision(int arr[], int key, int m)
{
    int i, newIndex, index;
    index = hashIndex(key, m);
    if (arr[index] == -1)
    {
        arr[index] = key;
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            newIndex = hashIndex(key + i, m);
            if (arr[newIndex] == -1)
            {
                arr[newIndex] = key;
                break;
            }
        }
    }
}

void deleteData(int arr[], int dataToBeDeleted, int m)
{
    int i, newIndex;
    int index = hashIndex(dataToBeDeleted, m);
    if (arr[index] == dataToBeDeleted)
    {
        arr[index] = -1;
        printf("\nThe data %d has been deleted from index %d which now has the value -1.", dataToBeDeleted, index);
    }
    else
    {
        for (i = 0; i <= m; i++)
        {
            newIndex = hashIndex(dataToBeDeleted + i, m);
            if (arr[newIndex] == dataToBeDeleted)
            {
                arr[newIndex] = -1;
                printf("\nThe data %d has been deleted from index %d which now has the value -1.", dataToBeDeleted, newIndex);
                break;
            }
        }
        if (i > m)
        {
            printf("\nDeletion Unsuccessfull, Data could not be found in the Array");
        }
    }
}

void searchData(int arr[], int dataToBeSearched, int m)
{
    int i, newIndex;
    int index = hashIndex(dataToBeSearched, m);
    if (arr[index] == dataToBeSearched)
    {
        printf("\nThe data %d has been found at index %d.", dataToBeSearched, index);
    }
    else
    {
        for (i = 0; i <= m; i++)
        {
            newIndex = hashIndex(dataToBeSearched + i, m);
            if (arr[newIndex] == dataToBeSearched)
            {
                printf("\nThe data %d has been found at index %d.", dataToBeSearched, newIndex);
                break;
            }
        }
        if (i > m)
        {
            printf("\nSearch Unsuccessfull, Data could not be found in the Array");
        }
    }
}

void display(int arr[], int m)
{
    printf("\nDisplaying data in the respective array index\n");
    printf("\nIndex: ");
    for (int i = 0; i < m; i++)
    {
        printf("\t%d", i);
    }
    printf("\nData: ");
    for (int i = 0; i < m; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int m, ch, key, count = 0;
    int dataToBeSearched;
    int dataTobeDeleted;
//    printf("********* '-1' IN THE ARRAY REPRESENT NULL DATA *********\n");

    printf("\n1. Insert Data in Hash Table\n2. Delete Data from Hash Table\n3. Search Data in Hash Table\n4. Display Hash Table\n5. Exit\n");
    printf("\nEnter no. of data you wanna enter in the Array: ");
    scanf("%d", &m);
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = -1;
    }

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (count < m)
            {
                do
                {
                    printf("Enter the  Key Value not equal to -1 you wanna place in the array: ");
                    scanf("%d", &key);
                    if (key == -1)
                    {
                        printf("\nPlease enter any Key value except -1 ");
                    }
                } while (key == -1);
                collision(arr, key, m);
                count++;
            }
            else
            {
                printf("\nInsertion Unsuccessfull, no more Input can be Taken\n");
            }
            break;
        case 2:
            
            printf("\nEnter the Data which you wanna delete from the array: ");
            scanf("%d", &dataTobeDeleted);
            deleteData(arr, dataTobeDeleted, m);
            break;
        case 3:
            
            printf("\nEnter the Data which you wanna search in the array: ");
            scanf("%d", &dataToBeSearched);
            searchData(arr, dataToBeSearched, m);
            break;
        case 4:
            display(arr, m);
            break;
        case 5:
            exit(0);
        default:
            printf("Please Enter appropriate choice as mentioned in the menu");
        }
    } while (ch != 0);
    return 0;
}