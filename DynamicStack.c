#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *Top=NULL;
void Push(){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    int val;
    if(!newNode){
       printf("OverFlow");
    }
    printf("Enter the Data :");
    scanf("%d",&val);
    newNode->data=val;
    newNode->next=Top;
    Top=newNode; 
}

void Pop(){
    struct Node *help;
    help=Top;
    int popped=help->data;
    Top=Top->next;
    free(help);
}

int Peek(){
    printf(" %d ",Top->data);
}
void Display(){
    struct Node*help;
    int i;
    help=Top;
    while(help!=NULL){
        printf(" %d ,",help->data);
        help=help->next;
    }  
}
int main() {
    int ch;
    do{
    printf("\n1.Insert\n2.DELETE\n3.DISPLAY\n4.Peak\n5.EXIT\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        Push();
        break;
    case 2:
        Pop();
        break;
    case 3:
       Display();
       break;
    case 4:
        Peek();
        break; 
    case 5:
       exit(0);
    }
    } while(ch!= 5);

    return 0;
}
