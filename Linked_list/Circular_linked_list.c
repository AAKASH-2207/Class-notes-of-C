/******************************************************************************
This code is for Double Linked List Implementation in C
This code is created by Aakash Sharma
For and as class notes of programs
Date: 14 May 2024
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
//insert node at the front
void insertfront(struct node** head, int data) {
    //allocate memory to the newnode
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    //assign date to the new node
    newnode -> data = data;
    //makeing new node as head
    newnode -> next = (*head);
    // assigning null to the previous
    newnode -> prev = NULL;
    // previous of head(now head is the second node) is newnode
    if((*head) != NULL)
        (*head) -> prev = newnode;
    //head points to the newnode
    (*head)->prev = newnode;
}
void insertafter(struct node* prev_node, int data){
    //check if previous node is NULL
    if(prev_node == NULL){
        printf("previous node cannot be null");
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    //data to newn node
    newnode -> data = data;
    //set next of newnode to next of prev node
    newnode -> next = prev_node -> next;
    // set next of prev node to newnode
    prev_node -> next = newnode;
    // set prev of new node to previous node
    newnode->prev = prev_node;
    //set prev of newndode's next to newnode
    if(newnode -> next != NULL)
        newnode ->next -> prev = newnode;
}
void insertend(struct node** head, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    //store the head node temporarily 
    struct node* temp = *head;
    //if the linked is empty, make newnode as head
    if(*head == NULL){
        newnode -> prev = NULL;
        *head = newnode;
        return;
    }
    while(temp -> next != NULL)
        temp = temp -> next;
    //the last node of the linked list is temp
    
    // assign next of the last node(temp) to newnode
    temp -> next = newnode;
    //assign prev of next node to temp
    newnode -> prev = temp;
}

void deletenode(struct node** head, struct node* del_node){
    //if head or del is null, deletion is not possible
    if(*head == NULL || del_node == NULL);
        return;
    // if del_node is the head node, point the head pointer to next of newnode
    if(*head = del_node)
        *head = del_node -> next;
    // if del_node is not at the last node, point the prev of node next to del_node to the previous of del_node
    if(del_node -> next != NULL)
        del_node ->next -> prev = del_node -> prev;
    //if del_node is not the first node, point the next of node previous to del_node to next of del_node
    if(del_node -> prev != NULL)
        del_node ->prev -> next = del_node -> next;
    //free the memory of del_node
    free(del_node);
}

void displaylist(struct node* node){
    struct node* last;
    while(node != NULL) {
        printf("%d -> ", node -> data);
        last = node;
        node = node -> next;
    }
    if(node == NULL)
        printf("NULL\n");
}
int main(){
    struct node* head = NULL;
    insertend(&head,12);
    insertfront(&head, 14);
    insertfront(&head,16);
    insertend(&head, 9);
    
    insertafter(head, 11);
    insertafter(head->next, 15);
    
    displaylist(head);
    
    deletenode(&head, head->next->next->next->next->next);
    
    displaylist(head);
}
/*
EXPECTED OUTPUT
12 -> 11 -> 15 -> 9 -> NULL
*/
