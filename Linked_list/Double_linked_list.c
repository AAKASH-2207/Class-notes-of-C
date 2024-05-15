/******************************************************************************
This code is for Circular Linked List Implementation in C
This code is created by Aakash Sharma
For and as class notes of programs
Date: 14 May 2024
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* addtoempty(struct node* last, int data){
    if (last != NULL) return last;
    //allocating memory
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    //assigning data to the new node
    newnode -> data = data;
    //last node to newnode
    last = newnode;
    //linking last to itself
    last -> next = last;
    return last;
}

struct node* addfront(struct node* last, int data){
    if(last == NULL) return addtoempty(last, data);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    //store the adress of the current first node in the newnode
    newnode -> next = last->next;
    //make newnode as head
    last -> next = newnode;
    return last;
}

struct node* addend(struct node* last, int data){
    if(last == NULL) return addtoempty(last, data);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    //store the address of the head node to next of newnode
    newnode -> next = last -> next;
    //point the current last node to the newnode
    last -> next = newnode;
    //make newnode as the last node
    last = newnode;
    return last;
}
//insert node after a specific node
struct node* addafter(struct node* last, int data, int item){
    if(last == NULL) return NULL;
    struct node *newnode, *p;
    p = last->next;
    do{
    //if the item is found, place after the newnode
        if(p -> data == item){
            newnode = (struct node*)malloc(sizeof(struct node));
            
            newnode ->data = data;
            // make the next of the current node as the next of newnode
            newnode ->next = p -> next;
            // put newnode to the nest of p 
            p->next = newnode;
            // if p is the last node, make newnode as the lat node
            if(p == last) last = newnode;
            return last;
        }
        p = p->next;
    } while(p != last -> next);
    printf("\n The given node is present in the list");
    return last;
}

void deletenode(struct node** last, int key){
    if(last ==  NULL) return;
    if((*last)->data == key && (*last)->next == *last){
        free (*last);
        *last = NULL;
        return;
    }
    struct node *temp = *last, *d;
    //if last is to be deletenode
    if((*last)->data == key){
        while (temp -> next != *last) temp = temp -> next;
        //point temp node the next of the last i.e. first node
        temp -> next = (*last) -> next;
        free(*last);
        *last = temp->next;
    }
    //trevel to the node to be deleted
    while(temp->next != *last && temp -> next -> data != key){
        temp = temp ->next;
    }
    //if node to be deleted is found
    if(temp -> next -> data == key){
        d = temp -> next;
        temp -> next = d-> next;
        free(d);
    }
}

void transverse(struct node* last) {
    struct node* p;
    if(last == NULL){
        printf("the list is empty");
        return;
    }
    p = last -> next;
    do{
        printf("%d ", p ->data);
        p = p->next;
    }while(p != last ->next);
}

int main(){
    struct node* last = NULL;
    last = addtoempty(last, 6);
    last = addend(last, 8);
    last = addfront(last, 2);
    
    last = addafter(last, 10, 2);
    
    transverse(last);
    deletenode(&last, 8);
    printf("\n");
    transverse(last);
    return 0;
}
/*
EXPECTED OUTPUT
2 10 6 8 
10 6 2
*/
