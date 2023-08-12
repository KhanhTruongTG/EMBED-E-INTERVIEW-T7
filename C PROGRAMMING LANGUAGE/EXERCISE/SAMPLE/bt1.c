#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    char* ptr;
    uint8_t length;
    uint8_t quantity;
    uint8_t status;
}words;

char string[] = "nam hoang tuan nam thai hoang thai hoang tuan yen";

words* splitString (char string[]) {
    uint8_t size = 1;
    char *ptr = string;
    while(*ptr != '\0') {
        if(*ptr == ' ') size++;
        ptr++;
    }

    words *array = (words*)malloc(sizeof(words)*size);
    uint8_t index = 0;
    uint8_t count = 1;
    array[index].ptr = string;
    while(*string != '\0') {
        if(*string == ' ') {
            array[index].length = count;
            count = 1;
            string++;
            array[++index].ptr = string;
        } 
        else{
            count++;
            string++;
        }
    }
    array[index].length = count;

    return array;
}



void test (words arr) {
    for (uint8_t i = 0; i < arr.length; i++) {
        printf("%c", arr.ptr[i]);
    }
}

bool isEqual (const char arr1[], const char arr2[]) {
    while (*arr1 == *arr2) {
        if(*arr1 == '\0') {
            return true;
        }
        arr1++;
        arr2++;
    }
   
    if(*arr1 > *arr2) {
        return true;
    }
     
    return false;

}

void sortAlphabet(words array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        words temp;
        for (int j = i + 1; j < size; j++) {
            if (isEqual(array[i].ptr, array[j].ptr)) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


void findName(words array[], uint8_t size) {
    uint8_t count = 0;
 
    uint8_t i_arr;
    uint8_t i_ptr = 0;
    
    while(i_arr < size) {

        for (uint8_t i = 0; i < size; i++) {
            while(array[i_arr].ptr[i_ptr] == array[i].ptr[i_ptr]) {
                i_ptr++;
                bool checkFinish = (array[i_arr].ptr[i_ptr] == ' ' || array[i_arr].ptr[i_ptr] =='\0')
                              && array[i].ptr[i_ptr] == ' ' || array[i].ptr[i_ptr] == '\0' ;
                if(checkFinish) {
                   count++;
                   if(count >= 2) array[i].status = 1;
                   i_ptr = 0;
                   break;
                }
            }
            i_ptr = 0;
        }
        array[i_arr].quantity = count;
        i_arr++;
        count = 0;
    }
}


void printWords (words array[], uint8_t size) {
    for(uint8_t i = 0; i < size; i++) {
        if(array[i].status == 0) {
            for(uint8_t j = 0; j < array[i].length - 1; j++) {
                printf("%c", array[i].ptr[j]);
            }
            printf(":\t%d\n", array[i].quantity);
        }
    }
}

uint8_t sizeStr (char string[]) {

    uint8_t size = 1;
    char *ptr = string;
    while(*ptr != '\0') {
        if (*ptr == ' ') size++;
        ptr++;
    }
    return size;

}


int main () {
    
    words* arr = splitString(string);

    uint8_t size = sizeStr(string);
   
    sortAlphabet(arr, size);
 
    // for(int i = 0; i < size; i++) {
    //     test(arr[i]);
    // }
    findName(arr, size);


    printWords(arr, size);
 

    
    return 0;
}