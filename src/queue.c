#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"


// ====================[Queue Part]==========================

/* Initializes the queue*/
void initQueue(Queue* Q){
    Q->front = NULL;
    Q->rear = NULL;
    Q->count = 0;
}

/* adds a new element to the rear of the queue*/
int enqueue(Queue* Q,int value){
    Node* node = malloc(sizeof(Node));      //reserve a place in memory for new double node
    if(node == NULL) return -1;             //return -1 if ther is failed allocation
    node->data = value;
    node->next = NULL;
    if(Q->front != NULL){           // checks if the queue is not empty
        Q->rear->next = node;       // makes the current rear point to the new node
        Q->rear = node;             // makes the new node the rear of the queue
    }else{
        Q->front = node;            // if empty, makes the new node both the front & the rear of the queue
        Q->rear = node;
    }
    Q->count++;                     // increments the count of the queue
    return 0;
}

/* removes the front element of the queue and returns its value or -1 if the queue is empty*/
int dequeue(Queue* Q){
    if(Q->front == NULL)return -1;
    Node* head;
    int value = Q->front->data;
    head = Q->front;
    Q->front = Q->front->next;      // makes the second node the new front of the queue
    if(Q->front == NULL)Q->rear = NULL; // sets rear to NULL if empty
    free(head);                    // frees the memory of the old front node
    Q->count--;                // decrements the count of the queue
    return value;
}

/* returns the value of the front element of the queue or -1 if the queue is empty*/
int front(Queue* Q){
    if(Q->front == NULL)return -1;
    return Q->front->data; 
}

/* returns the value of the rear element of the queue or -1 if the queue is empty*/
int rear(Queue* Q){
    if(Q->rear == NULL)return -1;
    return Q->rear->data; 
}