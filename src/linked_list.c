#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"


// ====================[Singly Linked List Part]==========================

/*initializes the list by setting te head to NULL and size to 0*/
void initList(List* L){
    L->head = NULL;
    L->size = 0;
}

/*inserts a new node at the beginning of the list*/
int insertBeginning(List* L, int value){
    if (L->size >= MAX_LIST_SIZE){
        printf("max size exceeded\n");
        return 2;
    }
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

/*inserts a new node at the end of the list*/
int insertEnd(List* L, int value){
    if (L->size >= MAX_LIST_SIZE){
        printf("max size exceeded\n");
        return 2;
    }
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

/*insert element at a given position*/
int insertAtPosition(List* L, int pos, int value) {

    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL){
        return -1;
    }
    

    newNode->data = value;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = L->head;
        L->head = newNode;
        return 1;
    }

    Node* current = L->head;
    int i = 0;

    while (current != NULL && i < pos - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        free(newNode);
        return 0;
    }

    newNode->next = current->next;
    current->next = newNode;

    return 1;
}

/*deletes the first node of the list and returns its value or -1 if the list is empty*/
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

/*delete the end of the list*/
int deleteEnd(List* L) {

    if (L->head == NULL){
        return -1;
    }

    Node* temp = L->head;
    int value;
    Node* prev = NULL;

    if (temp->next == NULL) {
        value = temp->data;
        free(temp);
        L->head = NULL;
        return value;
    }

    

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    value = temp->data;

    prev->next = NULL;
    free(temp);

    return value;
}

/*delete the node contains the targeted value */
int deleteByValue(List *L, int value) {

    if (L->head == NULL){
        return -1;                  //check if the list is empty
    }

    Node* temp;
    Node* p;

    if (L->head->data == value) {   //check the first node
        temp = L->head;
        L->head = temp->next;        
        free(temp);
        return 0;                   
    }

    p = L->head;
    int index = 1;


    while (p->next != NULL) {
        if (p->next->data == value) {   //starts from the head and checks the next node, if it holds the value the next node becomes the next of the next
            temp = p->next;
            p->next = temp->next;
            free(temp);
            return index;               // return the position 
        }
        p = p->next;
        index ++;
    }

    return -2;
}

/* Display the values of the linked list*/
void displayList(List* L){
    Node *temp;
    if (L->head == NULL){
        printf("list is empty\n");
        return;
    }
    temp = L->head;
    while (temp!= NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
}

/*search for a value in the list*/
Node* searchValue(List* L, int value)
{
    Node *temp = L->head;
    int index = 0;

    while(temp != NULL)
    {
        if(temp->data == value){
            printf("found at position: %d\n", index);
            return temp;
        }
        temp = temp->next;
        index ++;
    }
    return NULL;
}

/*reverse linked list*/
void reverseList(List* L)
{   
    if (L->head == NULL){
        printf("list is empty\n");
        return;
    }
    Node* prev = NULL;
    Node* curr = L->head;
    Node* next = NULL;

    while(curr != NULL)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    L->head = prev;
    printf("list reversed successfully\n");
}

/*Swaps data values between nodes to achieve the sorted order.*/
void sortListBubble(List* L) {
    if (L->head == NULL || L->head->next == NULL) { // Return immediately if the list is empty or has only one element.
        return;
    }
    int swapped;
    Node* ptr1;
    Node* lptr = NULL; // Points to the last sorted element to optimize the passes.
do {
        swapped = 0; // Reset swap flag at the start of each pass.
        ptr1 = L->head; // Always start from the head.
        // Traverse the list up to the already sorted part (lptr).
        while (ptr1->next != lptr) {
            // Compare adjacent node data.
            if (ptr1->data > ptr1->next->data) {
                // Swap the data values
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                
                swapped = 1;// Mark that a swap occurred.
            }
            ptr1 = ptr1->next;
        }
        // After each pass, the largest element is at the end.
        lptr = ptr1;

    } while (swapped);// Continue until a full pass completes without any swaps.
}

/*Merges two sorted lists (A and B) into a new sorted list (result).*/
void mergeSortedLists(List* A, List* B, List* result) {
   // Initialize the result list to be empty.
   initList(result);
    Node* pA = A->head;// Pointer to current node in list A.
    Node* pB = B->head;// Pointer to current node in list B.

    // Traverse both lists and pick the smaller element.
    while (pA != NULL && pB != NULL) {
        if (pA->data <= pB->data) {
            insertEnd(result, pA->data);
            pA = pA->next;// Advance list A pointer.
        } else {
            insertEnd(result, pB->data);
            pB = pB->next;// Advance list B pointer.
        }
    }

    // If list A still has remaining elements, append them to result.
    while (pA != NULL) {
        insertEnd(result, pA->data);
        pA = pA->next;
    }

    // If list B still has remaining elements, append them to result.
    while (pB != NULL) {
        insertEnd(result, pB->data);
        pB = pB->next;
    }
}

/*free the memory of linked list */
void freeLinkedList(Node *n){
    if (n==NULL){
        return;
    }
    Node *temp;
    while (n != NULL)
    {
        temp = n;
        n = n->next;
        free(temp);
    }
    printf("linked list has been freed successfully\n");
}


// ====================[Doubly Linked List Part]==========================

/*initializes the doubly linked list*/
void initListDLL(DLL* L){
    // Initialize an empty doubly linked list
    L->head = NULL;   // no first node
    L->tail = NULL;   // no last node
    L->size = 0;      // list contains 0 elements
}

/*inserts a new node at the beginning of the doubly linked list*/
int insertBeginningDLL(DLL* L, int value){
    DNode* dnode = malloc(sizeof(DNode));       //reserve a place in memory for new double node
    if(dnode == NULL) return -1;                //return -1 if ther is failed allocation  
    /*The new node points to the head*/
    dnode->data = value;
    dnode->prev = NULL;
    dnode->next = L->head;
    if(L->head != NULL)L->head->prev = dnode;
    /*update the head to the new node*/
    L->head = dnode;
    if(L->tail == NULL)L->tail = dnode;
    /*increment the size of the list*/
    L->size++;
    return 0; 
}

/*inserts a new node at the end of the doubly linked list*/
int insertEndDLL(DLL* L, int value){
    DNode* dnode = malloc(sizeof(DNode));       //reserve a place in memory for new double node
    if(dnode == NULL) return -1;                //return -1 if ther is failed allocation
    /*The new node points to the tail*/
    dnode->data = value;
    dnode->next = NULL;
    dnode->prev = L->tail;
    if(L->tail != NULL)L->tail->next = dnode;
    /*update the tail to the new node*/
    L->tail = dnode;
    if(L->head == NULL)L->head = dnode;
    /*increment the size of the list*/
    L->size++;
    return 0;
}


/* Delete node by value in Doubly Linked List */
int deleteByValueDLL(DLL* L, int value){

    if (L->head == NULL){
        return -1;
    }

    DNode *temp;
    DNode *p = L->head;

    if (L->head->data == value){
        temp = L->head;
        L->head = L->head->next;
        free(temp);
        L->size--;
        return 1;
    }
    p = L->head->next;
    while (p != NULL && p->data != value){
        p = p->next;
    }

    if (p == NULL){
        return 0;
    }else{
        temp = p;
        p->prev->next = p->next;
        free(temp);
        L->size--;
        return 1;
    }
}

/* Display from head to tail */
void displayForward(DLL* L){

    if (L->head == NULL){
        printf("List is empty\n");
        return;
    }

    DNode* p = L->head;

    while (p != NULL){

        printf("%d -> ", p->data);

        p = p->next;
    }

    printf("NULL\n");
}


/* Display from tail to head */
void displayBackward(DLL* L){

    if (L->tail == NULL){
        printf("List is empty\n");
        return;
    }

    DNode* p = L->tail;

    while (p != NULL){

        printf("%d -> ", p->data);

        p = p->prev;
    }

    printf("NULL\n");
}


/*free the memory of Doubly linked list */
void freeDLinkedList(DLL *L){
    if (L==NULL){
        return;
    }
    DNode *temp;
    while (L->head != NULL)
    {
        temp = L->head;
        L->head = L->head->next;
        free(temp);
    }
    printf("doubly linked list has been freed successfully\n");
}



