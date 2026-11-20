/*

Practical No. 2

Bubble Sort - Arrange Student Roll Numbers in Ascending Order.

*/

#include <stdio.h>

#define MAX 100

int main()
{
    int rollno[MAX], n;
    int i, j, temp;

     
    printf("Enter number of students (1 to %d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Invalid number of students!\n");
        return 1;
    }

    
    printf("\nEnter roll number of students:\n");
    for (i = 0; i < n; i++)
    {
        printf("Roll number %d: ", i + 1);
        if (scanf("%d", &rollno[i]) != 1)
        {
            printf("Invalid roll number!\n");
            return 1;
        }
    }

     
    for (i = 0; i < n - 1; i++)
    {
        printf("\nPass %d: ", i + 1);
        for (j = 0; j < n - i - 1; j++)
        {
            
            if (rollno[j] > rollno[j + 1])
            {
                 
                temp = rollno[j];
                rollno[j] = rollno[j + 1];
                rollno[j + 1] = temp;
            }
        }

         
        for (j = 0; j < n; j++)
        {
            printf("%d ", rollno[j]);
        }
    }

    
    printf("\n\nRoll numbers in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", rollno[i]);
    }
    printf("\n");

    return 0;
}
