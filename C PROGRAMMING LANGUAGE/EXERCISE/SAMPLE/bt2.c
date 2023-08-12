#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

char string [] = "mot con ga xe ra hai cai canh";

uint8_t sizeSpace() {
    uint8_t i = 0;
    char *ptr = string;
    while(*ptr != '\0') {
        if (*ptr == ' ') i++;
        ptr++;
   } 
   return i;
    
}

void addWord(char outPut[], uint8_t index) {
    static uint8_t i = 0;
    while(string[i] != '\0') {
        outPut[i] = string[index];
        i++;
        index++;
        if(string[index] == '\0'|| string[index] == ' ') {
            outPut[i] = ' ';
            i++;
            return;
        }
    }
}

void reverseWord (char outPut[]) {

    uint8_t size = sizeSpace();
    uint8_t count;
    uint8_t i = 0;
    uint8_t checkOut = 0;
    while(size != 0) {
        while(string[i] != '\0') {
            if(string[i] == ' ') {
                count++;
                if(count == size) {
                    addWord(outPut, i + 1);
                    count = 0;
                    size--;
                    checkOut = 1;
                    break;
                }     
            }
            if(checkOut == 1) break;
            i++;
        }
        checkOut = 0;
        i = 0;
    }
    addWord(outPut, 0);
    outPut[28] = '\0';


}

void prinOutPut(char outPut[]) {
    uint8_t i = 0;
    while(string[i] != '\0') {
        printf("%c", outPut[i]);
        i++;
    }
}


int main () {
    char outPut[29];
    reverseWord(outPut);
    prinOutPut(outPut);
}