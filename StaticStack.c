#include <stdio.h>
#include <stdlib.h>
#define Size 100

int Stack[100];
int Top=-1;

void Push(){
    int val;
    printf("Enter the Element :");
    scanf("%d",&val);
    if (Top==Size-1){
        printf("OverFLow");
    }
    Stack[++Top]=val;
    printf("%d Element Inserted",val);
}

void Pop(){
    
    if(Top==-1){
        printf("Underflow");
    }
    Stack[Top--]=Stack[Top];
    printf("New Top element : %d",Stack[Top]);
}

void Peek(){
    if(Top==-1){
        printf("Underflow");
        return;
    }
    printf("the top element is : %d",Stack[Top]);
}

void Display(){
    int i;
    if(Top==-1){
        printf("Underflow");
    }
    for(i=0;i<=Top;i++){
        printf(" %d ,",Stack[i]);
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
    } while(ch!= 4);

    return 0;
}

