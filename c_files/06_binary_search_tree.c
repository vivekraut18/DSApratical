/*

Title:- Binary Search Tree

Roll No:-CO2127

Vivek Raut

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *left, *right;
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

struct Node* createNode(int roll) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->roll = roll;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int roll) {
    if (root == NULL)
        return createNode(roll);
    if (roll < root->roll)
        root->left = insert(root->left, roll);
    else if (roll > root->roll)
        root->right = insert(root->right, roll);
    else
        printf("Duplicate roll number!\n");
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int roll) {
    if (root == NULL)
        return root;

    if (roll < root->roll)
        root->left = deleteNode(root->left, roll);
    else if (roll > root->roll)
        root->right = deleteNode(root->right, roll);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->roll = temp->roll;
        root->right = deleteNode(root->right, temp->roll);
    }
    return root;
}

int search(struct Node* root, int roll) {
    if (root == NULL)
        return 0;
    if (root->roll == roll)
        return 1;
    if (roll < root->roll)
        return search(root->left, roll);
    return search(root->right, roll);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->roll);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->roll);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->roll);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, roll;

    while (1) {
        printf("\n\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit\n");
        printf("Enter your choice: ");

        if (!readInt(&choice)) {
            printf("Invalid choice.\n");
            continue;
        }

        switch (choice) {
        case 1:
            printf("Enter roll number: ");
            if (!readInt(&roll)) {
                printf("Invalid roll number.\n");
                break;
            }
            root = insert(root, roll);
            break;

        case 2:
            printf("Enter roll number to delete: ");
            if (!readInt(&roll)) {
                printf("Invalid roll number.\n");
                break;
            }
            if (search(root, roll)) {
                root = deleteNode(root, roll);
                printf("Roll number deleted successfully.\n");
            } else {
                printf("Roll number not found.\n");
            }
            break;

        case 3:
            printf("Enter roll number to search: ");
            if (!readInt(&roll)) {
                printf("Invalid roll number.\n");
                break;
            }
            if (search(root, roll))
                printf("Roll number found.\n");
            else
                printf("Roll number not found.\n");
            break;

        case 4:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            freeTree(root);
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
