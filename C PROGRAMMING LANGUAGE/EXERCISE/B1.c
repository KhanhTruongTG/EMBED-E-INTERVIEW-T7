/* cho 1 chuoi ki tu ngau nhien, in ra so lan xuat hien cac ki tu do
char string[] = "nhat hoang tuan khanh nam nhat tuan hoang nam bao quoc bien khanh khang bien nam";
vd: nhat: xuat hien 2 lan
    hoang: xuat hien 2 lan
    nam: xuat hien 3 lan
    ..... */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isEqual(const char arr1[], const char arr2[]){
    while(*(arr1++) == *(arr2++)){
        if(*arr1 == '\0' || *arr2 == '\0'){
            return true;
        }
    }
    return false;
}
#define MAX 1000
int main(){
    char arr[MAX];
    printf("nhap mang: ");
    gets(arr);                          //nhập mảng từ bàn phím có dấu cách
    char mangTemp[MAX][MAX];            //mảng tạm để lưu lại kí tự, mỗi kí tự sẽ nằm ở 1 dòng của mảng 2 chiều -> để truy cập cả dòng thì chỉ cần mangTemp[1], mangTemp[2],...
    int n = 0;                          //đếm xem có bao nhiêu kí tự trong mảng
    
    //tách mảng thành những tên nhỏ
    char *token = strtok(arr, " ");
    while(token != NULL){
        strcpy(mangTemp[n], token);     //copy nội dung của token hiện tại vào dòng thứ n của mảng 2 chiều
        ++n;
        token = strtok(NULL, " ");      //tách từ cuối kí tự đầu
    }
    int mangDem[MAX]={0};               //tạo 1 mảng để lưu số lần xuất hiện
    
    //chạy vòng for duyệt qua các phần tử của mảng
    for(int i = 0; i < n; i++){
        if(mangDem[i] == 0){
            int count = 1;
            for(int j = i + 1; j < n; j++){         //chạy vòng for so sánh từng phần tử trong mảng
                if(isEqual(mangTemp[i], mangTemp[j])){
                    ++count;
                    mangDem[j]=1;
                }
            }
            printf("so lan xuat hien cua %s la %d\n", mangTemp[i], count);
        }
    }
    return 0;
}
