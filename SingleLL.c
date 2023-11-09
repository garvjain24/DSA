#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = 0;

void InsertAtBegin()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number to be Inserted: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}
void InsertAtEnd()
{
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number to be Inserted: ");
    scanf("%d", &newNode->data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}
void InsertAtMiddle()
{
    int n;
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter Position:");
    scanf("%d", &n);
    printf("Enter the number to be Inserted: ");
    scanf("%d", &newNode->data);
    if (n == 1)
    {
        InsertAtBegin();
    }
    else
    {
        int i = 0;
        while (i != n)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void DeleteAtBegin()
{
    struct Node *temp = head;
    head = head->next;
    printf("%d", temp->data);
    free(temp);
}
void DeleteAtEnd()
{
    struct Node *temp = head;
    struct Node *prev_temp = (struct Node *)malloc(sizeof(struct Node));
    while (temp->next != NULL)
    {
        prev_temp = temp;
        temp = temp->next;
    }
    prev_temp->next = NULL;
    free(temp);
}
void DeleteAtPos()
{
    int n;
    struct Node *temp = head;
    struct Node *prev_temp = (struct Node *)malloc(sizeof(struct Node));
    printf("enter Position:");
    scanf("%d", &n);
    if (n == 1)
    {
        DeleteAtBegin();
    }
    else
    {
        int i = 0;
        while (i != n)
        {
            prev_temp = temp;
            temp = temp->next;
            i++;
        }
        prev_temp->next = temp->next;
        free(temp);
    }
}
void Display()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    if (temp == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main()
{
    int choice;

    do
    {
        printf("1.Insert At Beginning\n");
        printf("2.Insert At End\n");
        printf("3.Insert At Position\n");
        printf("4.delete At Beginning\n");
        printf("5.delete At End\n");
        printf("6.delete At Position\n");
        printf("7.Display");
        printf("0.Exit\nEnter choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertAtBegin();
            break;
        case 2:
            InsertAtEnd();
            break;
        case 3:
            InsertAtMiddle();
            break;
        case 4:
            DeleteAtBegin();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            DeleteAtPos();
        case 7:
            Display();
            break;
        case 0:
            exit(0);
        default:
            printf("\nWrong Entry \n");
        }
    } while (choice != 0);
}
