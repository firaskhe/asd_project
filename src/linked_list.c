#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"



/*initializes the list by setting te head to NULL and size to 0*/
void initList(List* L){
    L->head = NULL;
    L->size = 0;
}

int insertBeginning(List* L, int value){
    Node* node = malloc(sizeof(Node));      // allocates memory for new node
    if (node == NULL){
        return -1;          // return -1 if memory allocation failed
    }
    node->data = value;
    node->next = L->head;   // points the new node to the head of the list
    L->head = node;         // makes the new node the head of the list
    L->size += 1;           // increments the size of the list
    return 0;
}

int insertEnd(List* L, int value){
    Node *p;
    if (L->head == NULL){
        return insertBeginning(L, value);
    }else{
        Node* node = malloc(sizeof(Node));  
        if (node == NULL){
            return -1;              // return -1 if memory allocation failed
        }
        p = L->head;

        while (p->next !=  NULL)    // finds the last node in the list
        {
            p = p->next;
        }
        
        node->data = value;
        node->next = NULL;      // points the NULL because it is the tail
        p->next = node;         // makes the new node the tail of the list
        L->size += 1;           // increments the size of the list
        return 0;
    }
}

int deleteBeginning(List* L){
    if (L->head == NULL){
        return -1;              // list is empty
    }
    int value = L->head->data;
    Node *scnd = L->head->next;
    free(L->head);
    L->head = scnd;
    L->size --;
    return value;
}