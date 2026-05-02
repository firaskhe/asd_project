#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "common.h"


/*======= Singly Linked List =======*/
void initList(List* L);
int insertBeginning(List* L, int value);
int insertEnd(List* L, int value);
int insertAtPosition(List* L, int pos, int value);
int deleteBeginning(List* L);
int deleteEnd(List* L);
int deleteByValue(List* L, int value);
Node* searchValue(List* L, int value);
void displayList(List* L);
void reverseList(List* L);
void sortListBubble(List* L);
void mergeSortedLists(List* A, List* B, List* result);


/*======= Doubly Linked List  =======*/
void initListDLL(DLL* L);
int insertBeginningDLL(DLL* L, int value);
int insertEndDLL(DLL* L, int value);
int deleteByValueDLL(DLL* L, int value);
void displayForward(DLL* L);
void displayBackward(DLL* L);


/*======= Stack  =======*/
void initStack(Stack* S);
int push(Stack* S, int value);
int pop(Stack* S);
int peek(Stack* S);
int isEmpty(Stack* S);

/*======= Queue  =======*/
void initQueue(Queue* Q);
int enqueue(Queue* Q, int value);
int dequeue(Queue* Q);
int front(Queue* Q);


#endif