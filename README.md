## Students

1. **Khedrouche Firas, G04**
2. **Dous Djaber, G04**
3. **LACHOUAG Mohamed Radouane, G04**
4. **BENALLEGUE Mohamed Rabie Rami, G04**
5. **ZEBBICHE Aboubakeur, G04**
6. **BENAIDJA Abdelali, G04**




## 📋 Table of content
- [List of implemented procedures and functions](#list-of-implemented-procedures-and-functions)
- [How to Execute](#how-to-execute)

## List of implemented procedures and functions


- [**Arrays**](#-arrays): **All**
- [**Linked Lists**](#-linked-lists): **All**
- [**Stack**](#-stack): **All**
- [**Queue**](#-queue): **All**
- [**Strings**](#-strings): **All**

## 🔰 Arrays
### 📌 Functions:
```
/* --- 1D Array --- */
void  initArray(int arr[], int* size);
void  printArray(int arr[], int size);
int   insertAt(int *arr, int* size, int index, int value);
int   deleteAt(int arr[], int* size, int index);
int   linearSearch(int arr[], int size, int value);
int   binarySearch(int arr[], int size, int value);
void  bubbleSort(int arr[], int size);
void  selectionSort(int arr[], int size);
void  insertionSort(int arr[], int size);
void  mergeSort(int arr[], int left, int right);
void  quickSort(int arr[], int low, int high);
int   findMax(int arr[], int size);
int   findMin(int arr[], int size);
int   sumArray(int arr[], int size);
double averageArray(int arr[], int size);
void  reverseArray(int arr[], int size);
void  rotateLeft(int arr[], int size, int k);
void  mergeSortedArrays(int a[], int na, int b[], int nb, int out[]);

/* --- 2D Matrix --- */
void  initMatrix(int m[][MAX_COLS], int* rows, int* cols);
void  printMatrix(int m[][MAX_COLS], int rows, int cols);
void  transposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]);
void  addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols);
void  multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int n);
int isSymmetric(int m[][MAX_COLS], int n);
int sumDiagonal(int m[][MAX_COLS], int n);
void sortRows(int m[][MAX_COLS], int rows, int cols);

/* --- Dynamic Array --- */
int*  createDynamicArray(int capacity);
void  fillArray(int* arr, int size);
void  printDynamicArray(int* arr, int size);
int*  resizeArray(int* arr, int *newCapacity);
void  freeArray(int* arr);
```
### 📌 Menu:
```
=== ARRAY MENU ===
1.  Insert element             2.  Delete element
3.  Search                     4.  Sort
5.  Find Max/Min               6.  Sum of the array
7.  Average of the array       8.  Reverse the array
9.  Rotate left                10. Merge two sorted arrays
11. Display array              12. Display D_Array
13. create dynamic array       14. fill dynamic array
15. resize dynamic array       16. free dynamic array
0.  Back

=== MATRIX MENU ===
1. Insert elements         2. create a matrix with swapped dimensions.
3. add two matrices        4. is symmetric
5. Display                 6. Sort Rows
7. sumDiagonal             8. Multiply Matrices
0. Back
```
## 🔰 Linked Lists
### 📌 Functions:
```
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
```
### 📌 Menu:
```
=== Singly Linked List ===

1. Insert at the beginning          2.  Insert at the end
3. Insert at position               4.  Delete by value
5. Delete from the beginning        6.  Delete from the end
7. Search                           8.  Reverse List
9. Sort List                        10. Merge 2 sorted lists
11. Dispaly List

=== Doubly Linked List ===

1. Insert at the beginning
2. Insert at the end
3. Delete by value
4. Display Forward
5. Display Backward
0. Back
```


## 🔰 Stack
### 📌 Functions:
```
/*======= Stack  =======*/
void initStack(Stack* S);
int push(Stack* S, int value);
int pop(Stack* S);
int peek(Stack* S);
int isEmpty(Stack* S);
```
### 📌 Menu:
```
=== Stack Menu ===

1. Push
2. POP
3. Peek
4. Is empty
0. Back
```

## 🔰 Queue
### 📌 Functions:
```
/*======= Queue  =======*/
void initQueue(Queue* Q);
int enqueue(Queue* Q, int value);
int dequeue(Queue* Q);
int front(Queue* Q);
int rear(Queue *Q);
```
### 📌 Menu:
```
=== Queue Menu ===

1. enqueue
2. dequeue
3. front
4. rear
0. Back
```

## 🔰 Strings
### 📌 Functions:
```
/*========= Strings =========*/
int my_strlen(const char* s);
char* my_strcpy(char* dest, const char* src);
char* my_strncpy(char* dest, const char* src, int n);
char* my_strcat(char* dest, const char* src);
int my_strcmp(const char* a, const char* b);
int my_strncmp(const char* a, const char* b, int n);
void toUpperCase(char* s);
void toLowerCase(char* s);
void reverseString(char* s);
int countVowels(const char* s);
int countConsonants(const char* s);
int countWords(const char* s);
int isPalindrome(const char* s);
void removeChar(char* s, char c);
void removeSpaces(char* s);
void substring(const char* src, int start, int len, char* dest);
int compareIgnoreCase(const char* a, const char* b);
```
### 📌 Menu:
```
=== STRINGS MENU ===
01. Enter string                   02. Lenght
03. Copy string                    04. Copy n chars
05. Combine two strings            06. Count words
07. Compare two strings            08. Compare n chars
09. To uppercase                   10. To lowercase
11. Reverse string                 12. IS Palindrome
13. Count vowels                   14. Count constants
15. Remove char                    16. Remove spaces
17. Sub string                     18. Compare with ignoring case
19. Print string
 0. Exit
```


## How to Execute


* First, download [**demo.exe**](https://github.com/firaskhe/asd_project/releases/tag/v1.1.0) or extract the files and compile the program using this command:
`gcc .\demo.c .\src\*.c -o demo`
* After execution you will get the main menu
* Choose which module you want to test
* For each module there are multiple methods and functions
* For arrays, you must insert the values of the array value by value for example:
```
=== ARRAY MENU ===
1.  Insert element             2.  Delete element
3.  Search                     4.  Sort
5.  Find Max/Min               6.  Sum of the array
7.  Average of the array       8.  Reverse the array
9.  Rotate left                10. Merge two sorted arrays
11. Display array              12. Display D_Array
13. create dynamic array       14. fill dynamic array
15. resize dynamic array       16. free dynamic array
0.  Back

Choice: 1
Index and value: 0 1
Choice: 1
Index and value: 1 2
Choice: 1
Index and value: 2 6
Choice: 11
size: 3 array: [1, 2, 6]
```
* Press 0 to go back to the previous menu
* To exit go back to main menu and press 0