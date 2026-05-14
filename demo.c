#include <stdio.h>
#include "include/array.h"
#include "include/linked_list.h"
#include "include/stack.h"
#include "include/queue.h"
#include "include/file_utils.h"
#include "include/string_utils.h"


/* Array Menu */
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
                
            default:
                break;
        }
    } while (choice != 0);
    if (dynamic_arr != NULL){
        freeArray(dynamic_arr);
    }
}

/* Matrix Menu */
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


/* Singly Linked List Menu */
void sLinkedListMenu(){
    int choice, value, r;
    List L;
    initList(&L);

    do{
        printf("\n=== Singly Linked List ===\n\n");
        printf(
            "1. Insert at the beginning          2.  Insert at the end\n"
            "3. Insert at position               4.  Delete by value\n"
            "5. Delete from the beginning        6.  Delete from the end\n"
            "7. Search                           8.  Reverse List\n"
            "9. Sort List                        10. Merge 2 sorted lists\n"
            "11. Dispaly List\n"
            "0. Back\nChoice: "
        );
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            r = insertBeginning(&L, value);
            if (r == -1){
                printf("failed\n");
            }else{
                printf("value inserted successfully\n");
            }
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            r = insertEnd(&L, value);
            switch (r)
            {
                case 0:
                    printf("value inserted successfully\n");
                    break;
                default:
                    printf("failed\n");
                    break;
            }
            break;
        case 3:
            printf("Enter index and value: ");
            scanf("%d %d", &r, &value);
            r = insertAtPosition(&L, r, value);
            switch(r){
                case -1:
                    printf("allocating memory for new node failed\n");
                    break;
                case 0:
                    printf("index out of range\n");
                    break;
                case 1:
                    printf("success\n");
                    break;
                default:
                    break;
            }
            break;
        case 4:
            printf("Enter value: ");
            scanf("%d", &value);
            r = deleteByValue(&L, value);
            switch (r){
            case -1:
                printf("the list is empty\n");
                break;
            case -2:
                printf("not found\n");
                break;
            default:
                printf("found at position: %d\n", r);
            }
            break;
        case 5:
            r = deleteBeginning(&L);
            switch (r)
            {
            case -1:
                printf("List is empty");
                break;
            
            default:
                printf("Head deleted and its value is: %d", r);
                break;
            }
            break;
        case 6:
            r = deleteEnd(&L);
            switch (r)
            {
            case -1:
                printf("List is empty");
                break;
            
            default:
                printf("End deleted and its value is: %d", r);
                break;
            }
            break;
        case 7:
            printf("Enter value: ");
            scanf("%d", &value);
            Node *node = searchValue(&L, value);
            if (node == NULL){
                printf("not found\n");
            }else{
                printf("address: %p\n", node);
            }
            break;
        case 8:
            reverseList(&L);
            break;
        case 9:
            sortListBubble(&L);
            printf("List sorted\n");
            break;
        case 10:
            List L2, L3;
            int size;
            initList(&L2);
            
            do{
                printf("enter the size of scnd list (max is 10): ");
                scanf("%d", &size);
            }while (size > 10);
            
            printf("enter values: ");
            while (size > 0)
            {
                scanf("%d", &value);
                insertEnd(&L2, value);
                size--;
            }
            sortListBubble(&L);
            sortListBubble(&L2);
            mergeSortedLists(&L, &L2, &L3);
            printf("lists merged successfully\n");
            displayList(&L3);
            freeLinkedList(L2.head);
            freeLinkedList(L3.head);
            break;
        case 11:
            displayList(&L);
        default:
            break;
        }

    }while (choice != 0);
    freeLinkedList(L.head);
}

/* Doubly Linked List Menu */
void dLinkedListMenu() {
    int choice, value, r;
    DLL dll;
    initListDLL(&dll);

    do{
        printf("\n=== Doubly Linked List ===\n\n");
        printf(
            "1. Insert at the beginning\n2. Insert at the end\n3. Delete by value\n4. Display Forward\n5. Display Backward\n"
            "0. Back\nChoice: "
        );
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter value: ");
            scanf("%d", &value);
            r = insertBeginningDLL(&dll, value);
            switch (r)
            {
            case 0:
                printf("success\n");
                break;
            default:
                printf("insertion failed\n");
                break;
            }
            break;
        case 2:
            printf("enter value: ");
            scanf("%d", &value);
            r = insertEndDLL(&dll, value);
            switch (r)
            {
            case 0:
                printf("success\n");
                break;
            default:
                printf("insertion failed\n");
                break;
            }
            break;
        case 3:
            printf("enter value: ");
            scanf("%d", &value);
            r = deleteByValueDLL(&dll, value);
            switch (r)
            {
            case -1:
                printf("memory allocation failed\n");
                break;
            case 0:
                printf("not found\n");
                break;
            case 1:
                printf("deleted successfully\n");
                break;
            default:
                break;
            }
            break;
        case 4:
            displayForward(&dll);
            break;
        case 5:
            displayBackward(&dll);
            break;
        default:
            break;
        }
    } while (choice != 0);
    freeDLinkedList(&dll);
}

/* Stack Menu */
void stackMenu(){
    int choice, value, r;
    Stack S;
    initStack(&S);

    do{
        printf("\n=== Stack Menu ===\n\n");
        printf(
            "1. Push\n2. POP\n3. Peek\n4. Is empty\n"
            "0. Back\nChoice: "
        );
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("enter value: ");
                scanf("%d", &value);
                r = push(&S, value);
                switch (r)
                {
                    case 0:
                        printf("success\n");
                        break;
                    default:
                        printf("push failed\n");
                        break;
                }
                break;
            case 2:
                r = pop(&S);
                switch (r)
                {
                    case -1:
                        printf("stack is empty\n");
                        break;
                    default:
                        printf("top is removed and its value is: %d\n", r);
                        break;
                }
                break;
            case 3:
                r = peek(&S);
                switch (r)
                {
                    case -1:
                        printf("stack is empty\n");
                        break;
                    default:
                        printf("Peek is: %d\n", r);
                        break;
                }
                break;
            case 4:
                if (isEmpty(&S)){
                    printf("YES\n");
                }else{
                    printf("NO\n");
                }
                break;
            default:
                break;
        }
    }while(choice!=0);
    freeLinkedList(S.top);
}

/* Queue Menu */
void queueMenu(){
    int choice, value, r;
    Queue Q;
    initQueue(&Q);

    do{
        printf("\n=== Queue Menu ===\n\n");
        printf(
            "1. enqueue\n2. dequeue\n3. front\n4. rear\n"
            "0. Back\nChoice: "
        );
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("enter value: ");
                scanf("%d", &value);
                r = enqueue(&Q, value);
                switch (r)
                {
                    case 0:
                        printf("success\n");
                        break;
                    default:
                        printf("enqueue failed\n");
                        break;
                }
                break;
            case 2:
                r = dequeue(&Q);
                switch (r)
                {
                    case -1:
                        printf("queue is empty\n");
                        break;
                    default:
                        printf("front is removed and its value is: %d\n", r);
                        break;
                }
                break;
            case 3:
                r = front(&Q);
                switch (r)
                {
                    case -1:
                        printf("queue is empty\n");
                        break;
                    default:
                        printf("front is: %d\n", r);
                        break;
                }
                break;
            case 4:
                r = rear(&Q);
                switch (r)
                {
                    case -1:
                        printf("queue is empty\n");
                        break;
                    default:
                        printf("rear is: %d\n", r);
                        break;
                }
                break;
            default:
                break;
        }
    }while(choice != 0);
    freeLinkedList(Q.front);
}

/* String Utils Menu */
void stringsMenu(){
    char str[MAX_STRING_LEN], dest[MAX_STRING_LEN];
    int choice, n, len;
    do {
        printf("\n=== STRINGS MENU ===\n");
        printf(
            "01. Enter string                   02. Lenght\n"
            "03. Copy string                    04. Copy n chars\n"
            "05. Combine two strings            06. Count words\n"
            "07. Compare two strings            08. Compare n chars\n"
            "09. To uppercase                   10. To lowercase\n"
            "11. Reverse string                 12. IS Palindrome\n"
            "13. Count vowels                   14. Count constants\n"
            "15. Remove char                    16. Remove spaces\n"
            "17. Sub string                     18. Compare with ignoring case\n"
            "19. Print string\n"
            " 0. Exit\nChoice: "
        );
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter a string: ");
                enterString(str);
                break;
            case 2:
                printf("length: %d\n", my_strlen(str));
                break;
            case 3:
                printf("string copied to dest: ");
                printString(my_strcpy(dest, str));
                break;
            case 4:
                printf("enter n: ");
                scanf("%d", &n);
                getchar();
                printf("copied to dest: ");
                printString(my_strncpy(dest, str, n));
                break;
            case 5:
                printf("Enter source: ");
                enterString(str);
                printf("Enter destination: ");
                enterString(dest);
                printString(my_strcat(dest, str));
                break;
            case 6:
                printf("number of words: %d", countWords(str));
                break;
            case 7:
                printf("Enter source: ");
                enterString(str);
                printf("Enter destination: ");
                enterString(dest);
                printf("%d\n", my_strcmp(str, dest));
                break;
            case 8:
                printf("Enter source: ");
                enterString(str);
                printf("Enter destination: ");
                enterString(dest);
                printf("enter n: ");
                scanf("%d", &n);
                printf("%d\n", my_strncmp(str, dest, n));
                break;
            case 9:
                toUpperCase(str);
                printf("converted to uppercase: %s\n", str);
                break;
            case 10:
                toLowerCase(str);
                printf("converted to lowercase: %s\n", str);
                break;
            case 11:
                reverseString(str);
                printf("reversed: %s\n", str);
                break;
            case 12:
                if (isPalindrome(str)){
                    printf("yes\n");
                }else{
                    printf("no\n");
                }
                break;
            case 13:
                printf("number of vowels: %d\n", countVowels(str));
                break;
            case 14:
                printf("number of constants: %d\n", countConsonants(str));
                break;
            case 15:
                char ch;
                getchar();
                printf("enter a char to remove: ");
                scanf("%c", &ch);
                removeChar(str, ch);
                printf("removed: %s", str);
                break;
            case 16:
                removeSpaces(str);
                printf("whitespaces removed: %s", str);
                break;
            case 17:
                dest[0] = '\0';
                printf("enter start and len: ");
                scanf("%d %d", &n, &len);
                substring(str, n, len, dest);
                printString(dest);
                break;
            case 18:
                printf("Enter source: ");
                enterString(str);
                printf("Enter destination: ");
                enterString(dest);
                printf("%d\n", compareIgnoreCase(str, dest));
                break;
            case 19:
                printString(str);
                break;
        }
    }while (choice != 0);
    
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
            case 3:
                int llch;
                do{
                    printf("1. Singly Linked List Menu\n2. Doubly Linked List Menu\n0. Back\nChoice: ");
                    scanf("%d", &llch);
                    switch(llch){
                        case 1:
                            sLinkedListMenu();
                            break;
                        case 2:
                            dLinkedListMenu();
                        default:
                            break;
                    
                    }
                    
                }while (llch!=0);
                break;
            case 4:
                stackMenu();
                break;
            case 5:
                queueMenu();
                break;
            case 7:
                stringsMenu();
                break;
            default:
                break;

                
        }
    } while (choice != 0);
    return 0;
}
