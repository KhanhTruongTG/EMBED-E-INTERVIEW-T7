#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX 100
//lưu địa chỉ và độ dài của từ
typedef struct{
    char *ptr;
    uint8_t length;
}words;

//so sánh giống nhau từ tước và từ sau
bool isEqual(const char arr1[], const char arr2[]){
    while (*arr1 == *arr2){
        if(*arr1 == '\0'){
            return true;
        }
        arr1++;
        arr2++;
    }
    return false;
}

//sắp xếp các từ theo thứ tự AlphaBet
bool sort(const char arr1[], const char arr2[]){
    while (*arr1 == *arr2){
        if(*arr1 == '\0'){
            return false;
        }
        arr1++;
        arr2++;
    }
    if(*arr1 > *arr2){
        return true;
    }
    return false;
}

//đếm số kí tự trong chuỗi
int num(char string[]){
    uint8_t size = 1;
    char *ptr = string;
    while(*ptr != '\0'){
        if(*ptr == ' '){
            size++;
        }
        ptr++;
    }
    return size;
}

//tách chuỗi và lưu vào struct
words* splitString(char string[]){
    int size = num(string);                                   //đếm số từ
    words *arrtemp = (words*)malloc(size*sizeof(words));      //cấp bộ nhớ cho mảng tạm kiểu struct bằng với số lượng từ
    uint8_t index = 0;                                        //địa chỉ của các phần tử trong struct 
    uint8_t count = 1;                                        //độ dài của kí tự
    arrtemp[index].ptr = string;                              //gán địa chỉ đầu tiên của mảng tạm bằng địa chỉ đầu tiên của chuỗi
    while(*string != '\0'){
        if(*string == ' '){
            *string = '\0';                 //xóa dấu cách
            count = 1;                      //reset count
            string++;                       //lấy địa chỉ sau dấu cách
            arrtemp[++index].ptr = string;  //arrtemp[1].ptr= địa chỉ h
        }
        else{
            count++;                        //tăng độ dài
            string++;                       //lấy địa chỉ kế tiếp
        }
        arrtemp[index].length = count;      //gán độ dài của kí tự
    }
    return arrtemp;
}

//sắp xếp theo thứ tự chữ cái
void sortAlphabet(words array[], int size){
    for(int i = 0; i < size-1; i++){
        words temp;
        for(int j = i + 1; j < size; j++){
            if(sort(array[i].ptr, array[j].ptr)){
                //swap vị trí
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

//in ra kí tự
void test(words test){
    for(int i = 0; i < test.length; i++){
        printf("%c", test.ptr[i]);
    }
}

//số lần xuất hiện
void occurence(words *list, int size)
{
    int count = 1;                                  //đếm số lần xuất hiện
    int i, j = 0;                                   //vị trí các từ
    for(i = 0; i < size - 1; i++) 
    {                                           
        j = j + 1;
        if(isEqual(list[i].ptr, list[j].ptr)){      //so sánh 2 từ kế bên, nếu giống (true) 
            count++;                                //thì tăng số lần xuất hiện
            if(i == size - 2){                      //so 2 giá trị cuối của chuỗi do đã sắp xếp theo thứ tự chữ cái
                test(list[i]);              //in ra luôn do đã giống nhau
                printf("\t%d\n", count);    //in ra số lần xuất hiện
            }
        }
        else{                                       //nếu khác (false)
            test(list[i]);                          //thì in ra
            printf("\t%d\n", count);                //in số lượng
            count = 1;          //reset count
            if(i == size-2){                        //so 2 giá trị cuối của chuỗi do đã sắp xếp theo thứ tự chữ cái
                test(list[j]);                      //in ra luôn do đã khác nhau
                printf("\t%d\n", count);            //in số lượng
            }
        }
    }
}


int main(){
    char arr[MAX] = "nhat hoang tuan khanh nam nhat tuan hoang nam bao quoc bien khanh khang bien nam";
    int size = num(arr);                    //gán biến size cho hàm đếm
    words *ptr2 = splitString(arr);         //gán con đến hàm tách
    sortAlphabet(ptr2, size);               //truyền vào để sắp xếp theo thứ tự chữ cái
    occurence(ptr2, size);                  //truyền vào để đếm và in ra số lần xuất hiện
    return 0;
}
