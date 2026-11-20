/*

Practical No. 1

Implement Array Operations - Insert, Delete, Display, Linear Search and Binary Search using C.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int readInt(int *x)
{
    int r = scanf("%d", x);
    if (r == 1)
        return 1;
    if (r == EOF)
    {
        printf("\n");
        exit(0);
    }
    while (getchar() != '\n')
        ;
    return 0;
}

int main()
{
    int arr[MAX], del, target, key, n = 0;
    int i, j, choice, flag;
    int low, high, mid, temp;

    do
    {
        printf("\n===MENU===");
        printf("\n 1. Insert marks");
        printf("\n 2. Delete");
        printf("\n 3. Display");
        printf("\n 4. Linear Search");
        printf("\n 5. Binary Search");
        printf("\n 6. Exit");
        printf("\n insert your choice:");

        if (!readInt(&choice))
        {
            printf("\n ENTER A VALID CHOICE!");
            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1: 
            printf("insert the size of array (1 to %d):", MAX);
            if (!readInt(&n) || n < 1 || n > MAX)
            {
                printf("\n Invalid size!");
                n = 0;
                break;
            }
            printf("enter the marks:");
            for (i = 0; i < n; i++)
            {
                if (!readInt(&arr[i]))
                {
                    printf("\n Invalid mark entered. Insert again.");
                    n = 0;
                    break;
                }
            }
            break;

        case 2: 
            if (n == 0)
            {
                printf("\n Array is empty.");
                break;
            }
            printf("\n ENTER POSITION BETWEEN 1 TO %d:", n);
            if (!readInt(&target) || target < 1 || target > n)
            {
                printf("\n Invalid position");
                break;
            }
            del = arr[target - 1];
            for (i = target - 1; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n = n - 1;
            printf("\n MARKS %d AT POSITION %d DELETED SUCCESSFULLY", del, target);
            break;

        case 3: 
            if (n == 0)
            {
                printf("\n Array is empty.");
                break;
            }
            printf("\n Marks are:");
            for (i = 0; i < n; i++)
            {
                printf("\n MARKS: %d", arr[i]);
            }
            break;

        case 4:
            flag = 0;
            printf("\n ENTER THE ELEMENT TO SEARCH:");
            if (!readInt(&key))
            {
                printf("\n Invalid input");
                break;
            }
            for (i = 0; i < n; i++)
            {
                if (arr[i] == key)
                {
                    flag = 1;
                    printf("\n Element found at position: %d", i + 1);
                    break;
                }
            }
            if (flag == 0)
            {
                printf("\n Marks %d not found", key);
            }
            break;

        case 5: 
            if (n == 0)
            {
                printf("\n Array is empty. Please insert marks first.");
                break;
            }
        
            for (i = 0; i < n - 1; i++)
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
            printf("\n Sorted array is:");
            for (i = 0; i < n; i++)
            {
                printf(" %d", arr[i]);
            }

        
            printf("\n ENTER THE ELEMENT TO SEARCH: ");
            if (!readInt(&key))
            {
                printf("\n Invalid input");
                break;
            }
            low = 0;
            high = n - 1;
            flag = 0;
            while (low <= high)
            {
                mid = low + (high - low) / 2;
                if (arr[mid] == key)
                {
                    flag = 1;
                    printf("\n Element found at sorted position: %d", mid + 1);
                    break;
                }
                else if (key < arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            if (flag == 0)
            {
                printf("\n Marks %d not found", key);
            }
            break;

        case 6:
            printf("\n Program Exit");
            break;

        default:
            printf("\n ENTER A VALID CHOICE!");
        }
    } while (choice != 6);

    return 0;
}
