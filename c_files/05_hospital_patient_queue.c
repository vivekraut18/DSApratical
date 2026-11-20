/*

Title:- Hospital Patient Registration System (Queue)

Roll No:-CO2127

Vivek Raut

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Patient {
    int id;
    char time[20];
};

 
struct Patient queue[MAX];
int front = 0, rear = -1, count = 0;


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

void addPatient() {
    struct Patient p;

    if (count == MAX) {
        printf("Queue is full.\n");
        return;
    }

    printf("Enter Patient ID: ");
    if (!readInt(&p.id)) {
        printf("Invalid Patient ID.\n");
        return;
    }
    printf("Enter Arrival Time: ");
    scanf("%19s", p.time);

    rear = (rear + 1) % MAX;
    queue[rear] = p;
    count++;
    printf("Patient added successfully.\n");
}

void attendPatient() {
    if (count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Attending Patient ID: %d\n", queue[front].id);
    printf("Arrival Time: %s\n", queue[front].time);

    front = (front + 1) % MAX;
    count--;
}

void viewPatients() {
    int i, idx;

    if (count == 0) {
        printf("No patients waiting.\n");
        return;
    }

    printf("\nWaiting Patients:\n");
    printf("Patient ID\tArrival Time\n");
    for (i = 0; i < count; i++) {
        idx = (front + i) % MAX;
        printf("%d\t\t%s\n", queue[idx].id, queue[idx].time);
    }
}

void isQueueEmpty() {
    if (count == 0)
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Hospital Patient Registration System ---\n");
        printf("1. Add Patient\n");
        printf("2. Attend Patient\n");
        printf("3. View Patients\n");
        printf("4. Check Queue Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (!readInt(&choice)) {
            printf("Invalid choice.\n");
            choice = 0;
            continue;
        }

        switch (choice) {
        case 1:
            addPatient();
            break;
        case 2:
            attendPatient();
            break;
        case 3:
            viewPatients();
            break;
        case 4:
            isQueueEmpty();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
