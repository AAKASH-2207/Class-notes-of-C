/******************************************************************************
This code is for Circular Queue Implementation in C
This code is created by Aakash Sharma
For and as class notes of programs
Date: 14 May 2024
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5

int items[MAX_SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return (front == rear + 1) || (front == 0 && rear == MAX_SIZE - 1);
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int element) {
    if (isFull()) {
        printf("The queue is full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX_SIZE;
        items[rear] = element;
        printf("%d is added to the queue\n", element);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("The queue is empty\n");
        return -1;
    } else {
        int dequeuedElement = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("%d is deleted from Queue\n", dequeuedElement);
        return dequeuedElement;
    }
}

void display() {
    int index;
    if (isEmpty()) {
        printf("There are no elements to print from the queue\n");
    } else {
        printf("Front -> %d\n", front);
        printf("Elements in Queue are: ");
        for (index = front; index!= rear; index = (index + 1) % MAX_SIZE) {
            printf("%d ", items[index]);
        }
        printf("%d ", items[index]);
        printf("\nRear -> %d\n", rear);
        printf("\n");
    }
}

int main() {
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    enqueue(60);

    dequeue();
    display();

    return 0;
}

/*
EXPECTED OUTPUT

The queue is empty
10 is added to the queue
20 is added to the queue
30 is added to the queue
40 is added to the queue
50 is added to the queue
Front -> 0
Elements in Queue are: 10 20 30 40 50 
Rear -> 4

The queue is full
10 is deleted from Queue
Front -> 1
Elements in Queue are: 20 30 40 50 
Rear -> 4

*/
