#include <stdio.h>
#include <stdlib.h>
#define max 2

Q[max]={NULL};
int front=-1;
int rear=-1;
isfull(){
    return (rear==max-1);
}
isEmpty(){
    return(front ==-1);
}
 
void enqueue(){
    int data;
    printf("Enter the element to be added: ");
    scanf("%d",&data);
    if(isfull()){
        printf("\nQueue is Full\n");
    }else{
        if(isEmpty()){
            front=0;
        }
        rear++;
        Q[rear]=data;
        printf("\n%d has been Inserted into queue \n",data);
    }
}
void Dequeue(){
    if(isEmpty()){
        printf("\nQueue is Empty\n");
    }else{
        int temp=Q[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }else{
            front++;
        }
    }
}
 
void Display(){
    int i;
    for (i=front;i<=rear;i++){
        printf("%d ",Q[i]);
    }
}
int main() {
    enqueue();
    enqueue();
    enqueue();
    Display();
    Dequeue();
    Display();
    return 0;
}