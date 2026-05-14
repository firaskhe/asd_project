#include <stdio.h>
#include "../include/string_utils.h"



/*get string input from user*/
void enterString(char *str){
    getchar();
    scanf("%256[^\n]", str);
}

/*print string*/
void printString(const char *str){
    printf("%s\n", str);
}

/*get the length of a string*/
int my_strlen(const char* s){
    int i = 0;
    while (s[i] != '\0')        // loop and increment until reaching the null char
    {
        i++;
    }
    return i;
}

/*copy a string from source to destination*/
char* my_strcpy(char* dest, const char* src){
    int i = 0;
    while(src[i] != '\0'){      // loop and copy until reaching the null char
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/*copy n characters of a string from source to destination*/
char* my_strncpy(char* dest, const char* src, int n){
    int i = 0;
    while(src[i] != '\0' && i < n){         // loop an increment until reaching the null char or the given number of chars
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}


/*concating two strings*/
char* my_strcat(char* dest, const char* src){
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    if (dest_len + src_len > MAX_STRING_LEN){       // check if src fits in dest 
        printf("max size exceeded\n");
        return dest;
    }

    for(int i = 0; i <= src_len; i++){          
        dest[dest_len+i] = src[i];          // append src to dest char by char
    }
    return dest;
}

/* compare character by character and return the difference a[i]-b[i] at the first mismatch or 0 if identical*/
int my_strcmp(const char* a, const char* b){
    int diff = 0;
    int i = 0;
    while ((a[i] != '\0' || b[i] != '\0') && diff == 0)     // check if they are identical (if both reaches the null at the same time before any mismatch) or stops at first mismatch
    {
        diff = a[i] - b[i];
        i++;
    }
    if (diff == 0){
        printf("identical, code: ");
    }else{
        printf("different, code: ");
    }
    return diff;
}

/* compare character by character and return the difference a[i]-b[i] at the first mismatch or 0 if identical, for n characters */
int my_strncmp(const char* a, const char* b, int n){
    int diff = 0;
    int i = 0;
    while ((a[i] != '\0' || b[i] != '\0') && diff == 0 && i < n)     // check if they are identical (if both reaches the null at the same time before any mismatch) or stops at first mismatch
    {
        diff = a[i] - b[i];
        i++;
    }
    if (diff == 0){
        printf("identical, code: ");
    }else{
        printf("different, code: ");
    }
    return diff;
}


/* convert lowercase characters to uppercase*/
void toUpperCase(char* s){
    int i = 0;
    while(s[i] != '\0'){
        if (s[i] >= 0x61 && s[i] <= 0x7A){      // check if the char is in lowercase
            s[i] = s[i] - 32;
        }
        i++;
    }
}

/* convert uppercase characters to lowercase*/
void toLowerCase(char* s){
    int i = 0;
    while(s[i] != '\0'){
        if (s[i] >= 0x41 && s[i] <= 0x5A){      // check if the char is in uppercase
            s[i] = s[i] + 32;
        }
        i++;
    }
}

/*reverse a string*/
void reverseString(char* s){
    int i = 0;
    int j = my_strlen(s) - 1;
    char temp;
    while (i < j)           // reverse with two pointers, one at the start and other one at the end and switch chars
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    
}

/*do a binary search to check if the char is a vowel*/
int isVowel(char s, int vowels[], int frst, int last){
    if (frst > last){
        return 0;
    }
    if (s == vowels[(frst+last)/2]){
        return 1;
    }else if (s > vowels[(frst+last)/2]){
        return isVowel(s, vowels, (frst+last)/2 + 1, last);     
    }else{
        return isVowel(s, vowels,  frst, (frst+last)/2 - 1);
    }
}

/*count the vowels in a string*/
int countVowels(const char *s){
    int v = 0;
    int vowels[] = {0x61, 0x65, 0x69, 0x6f, 0x75};   //sorted array of vowels to perform a binary search (faster than linear)
    for (int i = 0; i < my_strlen(s); i++){
        if (isVowel(s[i], vowels, 0, 4)){       // loop and check if it is a vowel and increment
            v++;
        }
    }
    return v;
}

/*count the constants in a string*/
int countConsonants(const char *s){
    int c = 0;
    int vowels[] = {0x61, 0x65, 0x69, 0x6f, 0x75};      //sorted array of vowels to perform a binary search (faster than linear)
    for (int i = 0; i < my_strlen(s); i++){
        if (s[i] >= 0x61 && s[i] <= 0x7A && !isVowel(s[i], vowels, 0, 4)){      // check if it is alpha and not a vowel
            c++;
        }
    }
    return c;
}

/*count the number of words in a string*/
int countWords(const char* s){
    int i = 0;
    int inWord = 0;
    int words = 0;
    while (s[i] != '\0'){
        if ((s[i] == ' ' || s[i] == '\t') && inWord != 0){       // checks if the pointer is not in a word
            inWord = 0;
        }
        if (s[i] != ' ' && s[i] != '\t' && inWord == 0){ // checks if the pointer enters a new word
            words++;                        // increment words
            inWord = 1;                     // set the inWord tracker to true
        }
        i++;
    }
    return words;
}

/*check if a string is palindrome */
int isPalindrome(const char* s){
    int i = 0;                  // pointer to the start
    int j = my_strlen(s) - 1;   // pointer to the end
    while (i<j){
        if (s[i] != s[j]){     // check for mismatch 
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

/*remove a specific character*/
void removeChar(char* s, char c){
    int i = 0;
    int j = 0;
    while (s[i] != '\0'){
        if (s[i] != c) {
            s[j] = s[i];
            i++;
            j++;
        }else{
            i++;
        }
    }
    s[j] = '\0';
}

/*remove whitespaces from a string*/
void removeSpaces(char* s){
    int i = 0;
    int j = 0;
    while (s[i] != '\0'){
        if (s[i] != ' ' && s[i] != '\t') {
            s[j] = s[i];
            i++;
            j++;
        }else{
            i++;
        }
    }
    s[j] = '\0';
}

/*copy characters from a given offset with a given length*/
void substring(const char* src, int start, int len, char* dest){
    if ((start+len) > my_strlen(src)){
        printf("strat + len exceeded the length of the source\n");
        return;
    }
    if (start < 0 || len < 1){
        printf("strat must be >= 0 and len must be >= 1\n");
        return;
    }

    for(int i = 0; i < len; i++){
        dest[i] = src[i+start];
    }

    dest[len] = '\0';
    
}

/*compare tow strings but igmoreCase */
int compareIgnoreCase(const char* a, const char* b){
    int diff = 0;
    int i = 0;
    char c, d;
    while ((a[i] != '\0' || b[i] != '\0') && diff == 0)     // check if they are identical (if both reaches the null at the same time before any mismatch) or stops at first mismatch
    {
        if (a[i] >= 0x41 && a[i] <= 0x5A){      // check if the char is in uppercase
            c = a[i] + 32;                      // convert first char to lowercase
        }else{                                              
            c = a[i];
        }
        if (b[i] >= 0x41 && b[i] <= 0x5A){      
            d = b[i] + 32;                      // convert second char to lowercase
        }else{
            d = b[i];
        }
        diff = c - d;
        i++;
    }
    if (diff == 0){
        printf("identical, code: ");
    }else{
        printf("different, code: ");
    }
    return diff;
}