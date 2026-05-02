#include <stdio.h>
#include "include/array.h"
#include "include/linked_list.h"
#include "include/stack.h"
#include "include/queue.h"
#include "include/file_utils.h"
#include "include/string_utils.h"



void arrayMenu() {
    int choice, sortChoice, searchChoice, arr[MAX_1D], size = 0, capacity = 0, newcapacity = 0, value, index, position;
    int *dynamic_arr = NULL;
    do {
        printf("\n=== ARRAY MENU ===\n");
        printf("1.  Insert element             2.  Delete element\n"
               "3.  Search                     4.  Sort\n"
               "5.  Find Max/Min               6.  Sum of the array\n"
               "7.  Average of the array       8.  Reverse the array\n"
               "9.  Rotate left                10. Merge two sorted arrays\n"
               "11. Display array              12. Display D_Array\n"
               "13. create dynamic array       14. fill dynamic array\n"
               "15. resize dynamic array       16. free dynamic array\n"
               "0.  Back\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Index and value: ");
                scanf("%d %d", &index, &value);
                insertAt(arr, &size, index, value);
                break;
            case 2:
                printf("Enter Index: ");
                scanf("%d", &index);
                deleteAt(arr, &size, index);
                break;
            case 3:
                printf("enter the value: ");
                scanf("%d", &value);
                printf("1. linearSearch\n2. binarySearch (array must be sorted)\nChoice: ");
                scanf("%d", &searchChoice);
                switch (searchChoice){
                    case 1:
                        position = linearSearch(arr, size, value);
                        break;
                    case 2:
                        position = binarySearch(arr, size, value);
                }
                if (position != -1){
                    printf("position: %d\n", position);
                }else{
                    printf("not found\n");
                }
                break;
            case 4:
                printf("1. bubbleSort\n2. selectionSort\n3. insertionSort\n4. mergeSort\n5. quickSort\n0. Back\nChoice: ");
                scanf("%d", &sortChoice);
                switch (sortChoice){
                    case 1:
                        bubbleSort(arr, size);
                        break;
                    case 2:
                        selectionSort(arr, size);
                        break;
                    case 3:
                        insertionSort(arr, size);
                        break;
                    case 4:
                        mergeSort(arr, 0, size-1);
                        break;
                    case 5:
                        quickSort(arr, 0, size-1);
                    default:
                        break;
                }
                break;
            case 5:
                printf("max: %d\n", findMax(arr, size));
                printf("Min: %d\n", findMin(arr, size));
                break;
            case 6:
                printf("sum: %d\n", sumArray(arr, size));
                break;
            case 7:
                printf("average: %.2f\n", averageArray(arr, size));
                break;
            case 8:
                reverseArray(arr, size);
                break;
            case 9:
                int k;
                printf("enter number of rotations: ");
                scanf("%d", &k);
                rotateLeft(arr, size, k);
                break;
            case 10:
                int arr2[MAX_1D], size2 = 0, out[MAX_1D];
                printf("Enter second array:\n");
                while((size + size2) < MAX_1D){
                    printf("Enter index(-1 to stop) and value: ");
                    scanf("%d %d", &index, &value);
                    if (index == -1){
                        break;
                    }else{
                        insertAt(arr2, &size2, index, value);
                    }
                }
                quickSort(arr, 0, size-1);
                quickSort(arr2, 0, size2-1);
                mergeSortedArrays(arr, size, arr2, size2, out);
                printf("Merged successfully:\n");
                printArray(out, size + size2);
                break;
            case 11: printArray(arr, size); break;
            case 12:
                if (capacity >= newcapacity){
                    printDynamicArray(dynamic_arr, capacity);
                }else{
                    printDynamicArray(dynamic_arr, newcapacity);
                }
                break;
            case 13:
                do{
                    printf("enter the size (0 < size =<20): ");
                    scanf("%d", &capacity);
                } while((capacity <= 0 || capacity > 20));
                dynamic_arr = createDynamicArray(capacity);
                break;
            case 14:
                if (capacity >= newcapacity){
                    fillArray(dynamic_arr, capacity);
                }else{
                    fillArray(dynamic_arr, newcapacity);
                }
                break;
            case 15:
                do{
                    printf("enter new capacity (must be greater than %d): ", capacity);
                    scanf("%d", &newcapacity);
                } while (newcapacity < capacity);
                dynamic_arr = resizeArray(dynamic_arr, &newcapacity);
                break;
            case 16:
                freeArray(dynamic_arr);
                dynamic_arr = NULL;
                capacity = 0;
                newcapacity = 0;
                break;
                
            /* ... other cases ... */
        }
    } while (choice != 0);
    if (dynamic_arr != NULL){
        freeArray(dynamic_arr);
    }
}


void matrixMenu() {
    int choice, matrix[MAX_ROWS][MAX_COLS], rows = 0, cols = 0;
    do {
        printf("\n=== MATRIX MENU ===\n");
        printf("1. Insert elements         2. create a matrix with swapped dimensions.\n"
               "3. add two matrices        4. is symmetric\n"
               "5. Display                 6. Sort Rows\n"
               "7. sumDiagonal             8. Multiply Matrices\n"
               "0. Back\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                initMatrix(matrix, &rows, &cols);
                break;
            case 2:
                int transMatrix[MAX_ROWS][MAX_COLS];
                transposeMatrix(matrix, rows, cols, transMatrix);
                break;
            case 3:
                int b[MAX_ROWS][MAX_COLS], r[MAX_ROWS][MAX_COLS], bRows, bCols;
                initMatrix(b, &bRows, &bCols);
                if (rows != bRows || cols != bCols){
                    printf("matrices must have the same dimentions\n");
                }else{
                    addMatrices(matrix, b, r, rows, cols);
                }
                break;
            case 4:
                if (rows != cols){
                    printf("rows and columns are not equal (not square). please recreate a square matrix first.\n");
                }else{
                    if (isSymmetric(matrix, rows) == 1){
                        printf("symmetric\n");
                    }else{
                        printf("not symmetric\n");
                    }
                }
                break;
            case 5:
                printMatrix(matrix, rows, cols);
                break;
            case 6:
                sortRows(matrix, rows, cols);
                break;
            case 7:
                if (rows != cols){
                    printf("matrix must be square\n");
                }else{
                    printf("sum diagonal: %d\n", sumDiagonal(matrix, rows));
                }
                break;
            case 8:
                if (rows != cols){
                    printf("rows and columns are not equal (not square). please recreate a square matrix first.\n");
                }else{
                    int matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS], rows2 = 0, cols2 = 0;
                    printf("Enter second matrix:\n");
                    initMatrix(matrix2, &rows2, &cols2);
                    if (rows != rows2 || cols != cols2){
                        printf("matrices dimensions do not match. please recreate matrices with the same dimensions first.\n");
                    }else{
                        multiplyMatrices(matrix, matrix2, result, rows);
                        printf("Result:\n");
                        printMatrix(result, rows, cols);
                    }
                }
        }
    } while (choice != 0);
}



int main() {
    int choice;
    do {
        printf("\n=== ADS2 PROJECT DEMO ===\n");
        printf("1. Arrays\n2. Matrices\n3. Linked Lists\n4. Stacks\n5. Queues\n6. File Handling\n7. String Utils\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: arrayMenu(); break;
            case 2:
                matrixMenu();
                break;
        }
    } while (choice != 0);
    return 0;
}
