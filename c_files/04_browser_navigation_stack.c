/*

Title:- Browser Navigation System Using Stack

Roll No:-CO2127

Vivek Raut

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 100
#define PAGE_SIZE 200

 
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
    char forwardstack[MAX_PAGES][PAGE_SIZE];
    char backstack[MAX_PAGES][PAGE_SIZE];
    char current[PAGE_SIZE] = "Home";
    char newpage[PAGE_SIZE];
    int backTop = -1;
    int forwardTop = -1;
    int choice;

    do
    {
        printf("\n--- MENU ---");
        printf("\n1. Visit New Page\n2. Back Navigation\n3. Forward Navigation\n4. Display Current Page\n5. EXIT");
        printf("\nEnter Your Choice: ");

        if (!readInt(&choice))
        {
            printf("Invalid Choice!\n");
            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("\nEnter new page: ");
            scanf("%199s", newpage);
            if (backTop == MAX_PAGES - 1)
            {
                printf("Back Stack Overflow!\n");
            }
            else
            {
                backTop++;
                strcpy(backstack[backTop], current);
                strcpy(current, newpage);
                forwardTop = -1; 
                printf("Visited: %s\n", current);
            }
            break;

        case 2:
            if (backTop == -1)
            {
                printf("No previous page available.\n");
            }
            else
            {
                if (forwardTop == MAX_PAGES - 1)
                {
                    printf("Forward Stack Overflow!\n");
                }
                else
                {
                    forwardTop++;
                    strcpy(forwardstack[forwardTop], current);
                    strcpy(current, backstack[backTop]);
                    backTop--;
                    printf("Back to: %s\n", current);
                }
            }
            break;

        case 3:
            if (forwardTop == -1)
            {
                printf("No forward page available.\n");
            }
            else
            {
                if (backTop == MAX_PAGES - 1)
                {
                    printf("Back Stack Overflow!\n");
                }
                else
                {
                    backTop++;
                    strcpy(backstack[backTop], current);
                    strcpy(current, forwardstack[forwardTop]);
                    forwardTop--;
                    printf("Forward to: %s\n", current);
                }
            }
            break;

        case 4:
            printf("Current Page: %s\n", current);
            break;

        case 5:
            printf("EXIT\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }
    } while (choice != 5);

    return 0;
}
