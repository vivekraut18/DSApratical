/*

Title:- social network connectivity

Roll No:-CO2127

Vivek Raut

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX] = {0};
int visited[MAX];
int n;

 
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

void addConnection(int u, int v)
{
    if (u < 0 || u >= n || v < 0 || v >= n)
    {
        printf("Invalid user ID!\n");
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
    printf("Connection added between User %d and User %d.\n", u, v);
}

void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++)
        {
            if (adj[current][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int current)
{
    int i;

    visited[current] = 1;
    printf("%d ", current);

    for (i = 0; i < n; i++)
    {
        if (adj[current][i] && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int choice, u, v, start, i, j;

    printf("Enter the number of users (1-%d): ", MAX);
    if (!readInt(&n) || n < 1 || n > MAX)
    {
        printf("Invalid number of users!\n");
        return 0;
    }

    do
    {
        printf("\n--- Social Network Connectivity ---\n");
        printf("1. Add Connection\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Display Adjacency Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (!readInt(&choice))
        {
            printf("Invalid choice! Try again.\n");
            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter two user IDs (0 to %d): ", n - 1);
            if (!readInt(&u) || !readInt(&v))
            {
                printf("Invalid user ID!\n");
                break;
            }
            addConnection(u, v);
            break;

        case 2:
            printf("Enter starting user ID: ");
            if (!readInt(&start) || start < 0 || start >= n)
            {
                printf("Invalid user ID!\n");
                break;
            }
            BFS(start);
            break;

        case 3:
            printf("Enter starting user ID: ");
            if (!readInt(&start) || start < 0 || start >= n)
            {
                printf("Invalid user ID!\n");
                break;
            }
            for (i = 0; i < n; i++)
                visited[i] = 0;
            printf("DFS Traversal: ");
            DFS(start);
            printf("\n");
            break;

        case 4:
            printf("Adjacency Matrix:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                    printf("%d ", adj[i][j]);
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
