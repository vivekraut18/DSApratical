/*

Practical No. 8

Library Book Indexing using Hash Table (Linear Probing)

Roll No: CO2127

*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];


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

void initialize() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

void insertBook(int key) {
    int index, pos, i;

    index = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++) {
        pos = (index + i) % TABLE_SIZE;

        if (hashTable[pos] == EMPTY) {
            hashTable[pos] = key;
            printf("Book ID inserted successfully at position %d\n", pos);
            return;
        }

        if (hashTable[pos] == key) {
            printf("Book ID already exists!\n");
            return;
        }
    }

    printf("Hash table is full!\n");
}

void searchBook(int key) {
    int index, pos, i;

    index = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++) {
        pos = (index + i) % TABLE_SIZE;

        if (hashTable[pos] == EMPTY) {
            printf("Book ID not found!\n");
            return;
        }

        if (hashTable[pos] == key) {
            printf("Book ID found at position %d\n", pos);
            return;
        }
    }

    printf("Book ID not found!\n");
}

void display() {
    int i;

    printf("\n----- HASH TABLE -----\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != EMPTY) {
            printf("Position %d : %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int choice, key;

    initialize();

    do {
        printf("\n===== LIBRARY BOOK INDEXING =====\n");
        printf("1. Insert Book ID\n");
        printf("2. Search Book ID\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (!readInt(&choice)) {
            printf("Invalid choice!\n");
            choice = 0;
            continue;
        }

        switch (choice) {
        case 1:
            printf("Enter Book ID: ");
            if (!readInt(&key) || key < 0) {   /* negative IDs would give a negative index; -1 is also the EMPTY marker */
                printf("Invalid Book ID! Enter a non-negative number.\n");
                break;
            }
            insertBook(key);
            break;

        case 2:
            printf("Enter Book ID to search: ");
            if (!readInt(&key) || key < 0) {
                printf("Invalid Book ID! Enter a non-negative number.\n");
                break;
            }
            searchBook(key);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
