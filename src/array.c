#include "../include/array.h"      // It represent the path towards my header (library)
#include <stdio.h>
#include <stdlib.h>


// ====================[Arrays Part]==========================

/* Initialize: set size to 0 — array is logically empty */ 
void initArray(int arr[], int* size) {
    *size = 0;
}

/* Print in [a, b, c] format */
void printArray(int arr[], int size) {
    printf("size: %d array: ", size);
    printf("[");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/* Insert value at index — shift elements right first */
int insertAt(int *arr, int* size, int index, int value) {
    if (index < 0 || index > *size) return -1;  // invalid index
    if (*size >= MAX_1D) return -1;             // array full
    int i;
    for (i = *size; i > index; i--)
        arr[i] = arr[i - 1];

    arr[index] = value;
    (*size)++;
    return 0;
}

/*
 Function: deleteAt
 ------------------
 Deletes an element at a given index from the array.
*/
int deleteAt(int arr[], int* size, int index){

    // Check for invalid index
	if (index < 0 || index >= *size) return -1;

    // Shift elements left to overwrite deleted element
	for (int i = index; i < *size - 1; i++){
		arr[i] = arr[i+1];
	}

    // Decrease array size
	(*size)--;

	return 0;
}

/*
 Function: linearSearch
 ----------------------
 Searches for a value in the array.
*/
int linearSearch(int arr[], int size, int value){

	for(int i = 0; i < size; i++){

        // If value found
		if(arr[i] == value){
			printf("index %d\n", i);

            // Return index immediately
			return i;
		}
	}

    // Not found
	return -1;
}

/* search for a value in a sorted array by checking the middle element then splitting the array to half and repeating the same process */
int binarySearch(int arr[], int size, int value){
    int first = 0;
    int last = size-1;
    while(first <= last){
        int mid = (last + first)/2;
        if (arr[mid] == value){
            return mid;
        }else if(arr[mid] < value){
            first = mid +1;
        }else{
            last = mid -1;
        }
    }
    return -1;    // value not found
}

/*sorts the list by comparing each element to its adjacent and swap them if the previous is greater than the other*/
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = 0;

        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        if (swapped == 0)       // this means the array is already sorted and breaks the loop
            break;
    }
}

/*insertion sort*/
void insertionSort(int arr[], int size) {
    int i, key, j;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

/*
 Function: merge
 ---------------
 Merges two sorted subarrays into one sorted array.
*/
void merge(int arr[], int left, int mid, int right) {

    int i, j, k;

    // Sizes of the two subarrays
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    // Create temporary arrays
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    // Copy data into temp arrays
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[]
    i = 0; 
    j = 0; 
    k = left;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements (if any)
    while (i < n1) 
        arr[k++] = L[i++];

    while (j < n2) 
        arr[k++] = R[j++];

    // Free allocated memory
    free(L);
    free(R);
}

/*
 Function: mergeSort
 -------------------
 Recursive merge sort algorithm.
*/
void mergeSort(int arr[], int left, int right) {

    if (left < right) {

        // Find middle index
        int mid = left + (right - left) / 2;

        // Sort left half
        mergeSort(arr, left, mid);

        // Sort right half
        mergeSort(arr, mid + 1, right);

        // Merge both halves
        merge(arr, left, mid, right);
    }
}

/* Sorts the  Array by finding the minimum element in the unsorted portion and swapping it with the first element */
void selectionSort(int arr[], int size) {
    int i, j, min_idx, temp;

    for (i = 0; i < size - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

/* sort the array by picking a pivot (last element in this case), partitioning elements smaller/larger around it, then recursively sorting both halves. In-place.*/
void quickSort(int *arr, int low, int high){
    if (high <= low){  // base case
        return;
    }
    int temp;
    int j=low-1;
    int pivot = arr[high];
    for (int i=low;i<=high; i++){
        if (i == high){
            j++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j]= temp;
        }else if (arr[i]<pivot){
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quickSort(arr, low, j-1);    // do the same with the array before the pivot
    quickSort(arr, j+1, high);  // do the same with the array after the pivot
}

/* finds the max element in the array */
int findMax(int arr[], int size) {
    int max = arr[0];  

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/* find the minimum element the array*/
int findMin(int arr[], int size) {
    int min = arr[0]; 

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

/* calculate the sum of all element in array*/
int sumArray(int arr[], int size) {
    int sum=0;
    // Find the sum of all element in array
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum;
}

/*calculates the average of the array*/
double averageArray(int arr[] ,int size){
 	double s = (double)sumArray(arr,size)/(double)size ;
 	return s ;
}

/*reverse the array by going in both directions of the array and swapping elements*/
void reverseArray(int arr[], int size){
    int temp;
    for (int i=0; i<size/2; i++){
        temp = arr[i];         
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}

/* Merges two sorted arrays into one sorted array */
void mergeSortedArrays(int a[], int na, int b[], int nb, int out[]) {
    int i = 0, j = 0, k = 0; 

    // 1. Compare and merge elements while both arrays have items
    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            out[k] = a[i];
            i++;
        } else {
            out[k] = b[j];
            j++;
        }
        k++;
    }

    // copy remaining elements
    
    while (i < na) {
        out[k] = a[i];
        i++;
        k++;
    }

    while (j < nb) {
        out[k] = b[j];
        j++;
        k++;
    }
}

/*moves elements left one position at a time k times*/
void rotateLeft(int arr[], int size, int k) {
    if (size == 0) return;

    k = k % size;
    for (int i=0; i<k;i++){
        int first = arr[0];
        for(int j = 0;j<size-1; j++){
            arr[j] = arr[j+1];
        }
        arr[size-1] = first;
    }
}




// ====================[Matrices Part]==========================

/* read values of the elements of the matrix */
void  initMatrix(int m[][MAX_COLS], int *rows, int *cols){
    do{
        printf("enter number of rows and columns (max is 20): ");
        scanf("%d %d", rows, cols);
    } while((*rows > MAX_ROWS || *cols > MAX_COLS));
    printf("enter values: ");
    for (int i=0; i < *rows; i++){
        for (int j=0; j < *cols; j++){
            scanf("%d", &m[i][j]);
        }
    }
}

/*
 Function: printMatrix
 ---------------------
 Prints a matrix in row-column format.
*/
void printMatrix(int m[][MAX_COLS], int rows, int cols){
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("%4d\t", m[i][j]); // print element
		}
		printf("\n"); // new line after each row
    }
    printf("\n");
}

/*
 Function: isSymmetric
 ---------------------
 Checks if a square matrix is symmetric.
*/
int isSymmetric(int m[][MAX_COLS], int n){

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(m[i][j] != m[j][i]){
                return -1; // not symmetric
            }
        }
    }

    return 0; // symmetric
}

/*create a matrix with swapped dimensions */
void transposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]){
    for (int i=0; i < rows; i++){
        for (int j=0; j < cols; j++){
            out[j][i] = m[i][j];
        }
    }

    printMatrix(out, cols, rows);
}

void multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int n) {
    int i, j, k;

    // 1. Iterate through the rows of the first matrix (a)
    for (i = 0; i < n; i++) {
        
        // 2. Iterate through the columns of the second matrix (b)
        for (j = 0; j < n; j++) {
            
            // Initialize the result element to 0 before accumulating the sum
            r[i][j] = 0;
            
            // 3. Calculate the dot product and add it to the accumulator
            for (k = 0; k < n; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

/*add two matrices*/
void  addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols){
    for (int i = 0;i < rows;i++){
        for (int j = 0;j < cols;j++){
            r[i][j] = a[i][j] + b[i][j];
        }
    }

    printMatrix(r, rows, cols);
}

/*sum diagonal*/
int sumDiagonal(int m[][MAX_COLS], int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += m[i][i];
    }
    return sum;
}

/*
 Function: sortRows
 ------------------
 Sorts each row of a matrix in ascending order.

 m    : matrix
 rows : number of rows
 cols : number of columns
*/
void sortRows(int m[][MAX_COLS], int rows, int cols){

    // Loop through each row
    for(int i = 0; i < rows; i++){

        // Apply Bubble Sort on row i
        for(int j = 0; j < cols - 1; j++){
            for(int k = 0; k < cols - j - 1; k++){

                // Compare adjacent elements
                if(m[i][k] > m[i][k + 1]){

                    // Swap
                    int temp = m[i][k];
                    m[i][k] = m[i][k + 1];
                    m[i][k + 1] = temp;
                }
            }
        }
    }
}



// ====================[Dynamic Array Part]==========================

/* creates dynamic array*/
int*  createDynamicArray(int capacity){
    int *ptr;
    ptr = malloc(capacity * sizeof(int));

    if (ptr == NULL){
        printf("error: couldn't creat array\n");
    }else{
        printf("dynamic array created successfully\n");
    }
    return ptr;
}

/*print elements of dynamic array*/
void  printDynamicArray(int* arr, int size){
    printf("size: %d, array: [", size);
    if (arr != NULL){
        for (int i=0; i < size; i++){
            if(i == size-1){
                printf("%d", *(arr + i));
            }else{
                printf("%d, ", *(arr + i));
            }
        }
    }
    printf("]\n");
}

/* fill dynamic array*/
void  fillArray(int* arr, int size){
    if (arr != NULL){
        printf("enter values: ");
        for (int i=0; i < size; i++){
            scanf("%d", (arr + i));
        }
    }
}

/* resize dynamic array*/
int*  resizeArray(int* arr, int *newCapacity){
    int *temp;
    if (arr != NULL){
        temp = realloc(arr, *newCapacity * sizeof(int));    // store the return of realloc in a temporary var so it does not override the array's pointer in case of failure
    }
    if (temp == NULL){
        printf("resizing failed\n");
        *newCapacity = 0;
    }else{
        arr = temp;
        printf("array has beed resized successfully\n");
    }
    return arr;
}

/*free the memory of the dynamic array*/
void  freeArray(int* arr){
    free(arr);
    printf("array has beed freed successfully\n");
}