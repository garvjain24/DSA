#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to remove an element from the queue
int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        item = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return item;
    }
}

// Function to display the queue
void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    display();

    int dequeued = dequeue();
    if (dequeued != -1) {
        printf("Dequeued element: %d\n", dequeued);
    }

    display();

    enqueue(5);
    enqueue(6);

    display();

    return 0;
}
