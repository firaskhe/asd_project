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
void freeLinkedList(Node *n);


/*======= Doubly Linked List  =======*/
void initListDLL(DLL* L);
int insertBeginningDLL(DLL* L, int value);
int insertEndDLL(DLL* L, int value);
int deleteByValueDLL(DLL* L, int value);
void displayForward(DLL* L);
void displayBackward(DLL* L);
void freeDLinkedList(DLL *L);


#endif