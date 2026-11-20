/*

Title: Dynamic Contact List Management Using Linked List

Roll No: CO2127

VIVEK RAUT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{
    char name[30];
    char phone[16];    
    struct contact *next;
};

 
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

 
struct contact *readContact(void)
{
    struct contact *newnode = (struct contact *)malloc(sizeof(struct contact));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    printf("Enter name: ");
    if (scanf("%29s", newnode->name) != 1)
    {
        free(newnode);
        return NULL;
    }
    printf("Enter phone: ");
    if (scanf("%15s", newnode->phone) != 1)
    {
        free(newnode);
        return NULL;
    }
    newnode->next = NULL;
    return newnode;
}

int main()
{
    struct contact *head = NULL;
    struct contact *newnode, *temp, *prev;
    char name[30];
    int choice;

    do
    {
        printf("\n==== MENU ====");
        printf("\n1.Insert New Contact :");
        printf("\n2.Insert New Contact At End :");
        printf("\n3.Delete a Contact Using Name :");
        printf("\n4.Search Contact :");
        printf("\n5.Display All Contacts :");
        printf("\n6.Exit");
        printf("\nEnter Your Choice : ");

        if (!readInt(&choice))
        {
            printf("Invalid choice!\n");
            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1:  
            newnode = readContact();
            if (newnode == NULL)
                break;
            newnode->next = head;
            head = newnode;
            break;

        case 2:  
            newnode = readContact();
            if (newnode == NULL)
                break;
            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
            break;

        case 3:  
            printf("Enter name to delete: ");
            scanf("%29s", name);
            temp = head;
            prev = NULL;
            while (temp != NULL && strcmp(temp->name, name) != 0)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("Contact not found.\n");
            }
            else
            {
                if (prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                free(temp);
                printf("Contact deleted successfully.\n");
            }
            break;

        case 4: 
            printf("Enter name to search: ");
            scanf("%29s", name);
            temp = head;
            while (temp != NULL)
            {
                if (strcmp(temp->name, name) == 0)
                {
                    printf("Contact Found\n");
                    printf("Name:%s\n", temp->name);
                    printf("Phone:%s\n", temp->phone);
                    break;
                }
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("Contact not found.\n");
            }
            break;

        case 5:  
            if (head == NULL)
            {
                printf("No contacts to display.\n");
            }
            temp = head;
            while (temp != NULL)
            {
                printf("Name:%s\n", temp->name);
                printf("Phone:%s\n", temp->phone);
                temp = temp->next;
            }
            break;

        case 6: 
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

     
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
