## Students

1. **Khedrouche Firas, G04**
2. **Dous Djaber, G04**
3. **LACHOUAG Mohamed Radouane, G04**
4. **BENALLEGUE Mohamed Rabie Rami, G04**
5. **ZEBBICHE Aboubakeur, G04**
6. **BENAIDJA Abdelali, G04**




## List of implemented procédures and functions
1. **Module 1-Arrays (31)**:
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




## How to Execute



* You need to execute demo.exe, then you will get the main menu
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