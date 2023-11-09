#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *front;
struct Node *rear;

void enQueue(){
    int data;
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data :");
    scanf("%d",&data);
    newNode->data=data;
    newNode->next=NULL;
    if (front==NULL){
        rear=front=newNode;
    }
    rear->next=newNode;
    rear=newNode;
}

void deQueue(){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    if(front==NULL){
        printf("Empty");

    }
    if(front==rear){
        free(front);
        front=rear=NULL;
        return;
    }
    else{
        temp=front;
        front=front->next;
        free(temp);
    }
}
void display(){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp=front;
    while(temp!=NULL){
        printf(" %d ,",temp->data);
        temp=temp->next;
    }
}
int main()
{
    front = NULL;
    rear = NULL;
    int ch;
    do
    {
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    } while (ch != 4);

    return 0;
}