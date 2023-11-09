#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *tail, *head;

void InsertAtBegin()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter Data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void InsertAtEnd()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void InsertAtPos()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int Pos, i = 0;
    printf("\nEnter Position to Insert the node :");
    scanf("%d", &Pos);
    printf("enter Data: ");
    scanf("%d", &newNode->data);
    if (Pos == 1)
    {
        InsertAtBegin();
    }
    else
    {
        while (i < Pos && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            printf("Position is not available\n");
        }
        else
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL)
                newNode->next->prev = newNode;
            temp->next = newNode;
        }
    }
}
void DeleteAtBegin(){
    struct Node *temp=head;
    if(head==NULL){
        printf("List is empty.\n");
    }
    else{
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    }
}
void DeleteAtEnd(){
    struct Node* temp=tail;
    if(tail==NULL){
        printf("List is empty.\n");
    }
    temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}   
void DeleteAtPos(){
    int Pos ,i ;
    struct Node *temp=head;
    printf("\nEnter Position to Insert the node :");
    scanf("%d", &Pos);
    for (i=0;i<Pos;i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    printf("node at pos %d with value %d is deleted",Pos,temp->data);
    free(temp);
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
            InsertAtPos();
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