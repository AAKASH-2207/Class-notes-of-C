/******************************************************************************
This code is for Stack Implementation in C
This code is created by Aakash Sharma
For and as class notes of programs
Date: 13 May 2024
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define max 100
int count = 0;

struct Stack{
    int arr[max];
    int top;
};
typedef struct Stack Stack;

void initialize(Stack *stack){
    stack -> top = -1;
}

int isfull(Stack *s){
    if(s -> top == max - 1){
        return 1;
    }else{
        return 0;
    }
}
int isempty(Stack *s){
    if(s -> top == -1){
        return 1;
    }else{
        return 0;
    }
}
void push(Stack *s, int num){
    if(isfull(s)){
        printf("Stack is Full!");
    }else{
        s -> top++;
        s -> arr[s->top] = num;
    }
    count++;
}
void pop(Stack *s){
    if(isempty(s)){
        printf("The Stack is empty");
    }else{
        printf("item popped = %d",s->arr[s->top]);
        s -> top--;
    }
    count--;
}
void printingstack(Stack *s){
    printf("Stack: ");
    for(int i = 1 ; i <= count ; i++){
        printf("%d ",s -> arr[i]);
    }
    printf("\n");
}
int main()
{
    int ch;
    Stack *s = (Stack *)malloc(sizeof(Stack));
    push(s, 2);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printingstack(s);

    pop(s);

    printf("\nAfter popping out\n");
    printingstack(s);
    return 0;
}

/*
EXPECETED OUTPUT:
Stack: 2 2 3 4 
item popped = 4
After popping out
Stack: 2 2 3 
 */
