#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"



// ====================[Stack Part]==========================

/* Initializes the stack*/
void initStack(Stack* S){
    S->top = NULL;
}

/* adds a new element to the top of the stack*/
int push(Stack* S, int value){
    Node* node = malloc(sizeof(Node));
    if (node == NULL){
        return -1;
    }
    node->data = value;
    node->next = S->top;
    S->top = node;
    return 0;
}

/* removes the top element of the stack and returns its value or -1 if the stack is empty*/
int pop(Stack* S){
    if(S->top == NULL)return -1;
    Node* head;
    int value = S->top->data;
    head = S->top;
    S->top = S->top->next;
    free(head);
    return value;
}

/* returns the value of the top element of the stack or -1 if the stack is empty*/
int peek(Stack* S){
    if(S->top == NULL)return -1;
    return S->top->data;
}

/* checks if the stack is empty*/
int isEmpty(Stack* S){
    return S->top == NULL;
}