/******************************************************************************
This code is for Queue Implementation in C
This code is created by Aakash Sharma
For and as class notes of programs
Date: 14 May 2024
*******************************************************************************/
#include <stdio.h>
#define max 10

int items[max], front = -1, rear = -1;

void enqueue(int num){
    if(rear == max -  1){
        printf("The queue is full");
    }else{
        if(front == -1){
            front = 0;}
        rear++;
        items[rear] = num;
        printf("\n%d is added to the queue",num);
        
    }
}

void dequeue(){
    if(rear == front){
        printf("\nthe queue is empty");
    }else{
        printf("\n%d is deleted from Queue",items[front]);
        front++;
        if(front == rear){
            front = rear = -1;
        }
    }
}

void display(){
    if(rear = -1){
        printf("\nthere are no elements to print from the queue");
    }else{
        int i;
        printf("\n elements in Queue are");
        for(i = front; i < rear ; i++){
            printf("%d",items[i]);
        }
        printf("\n");
    }
}

int main(){
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();
    
    dequeue();
    display();
}

/*
EXPECTED OUTPUT
the queue is empty
10 is added to the queue
20 is added to the queue
30 is added to the queue
40 is added to the queue
there are no elements to print from the queue
10 is deleted from Queue
there are no elements to print from the queue

*/
