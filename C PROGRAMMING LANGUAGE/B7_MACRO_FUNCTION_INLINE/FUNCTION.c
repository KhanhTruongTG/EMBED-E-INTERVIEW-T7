#include <stdio.h>
#include <stdint.h>

void tong (int a, int b){
    printf("tong a va b: %d\n",a+b);
}                                            //VD hàm này có địa chỉ từ 0xC1 đến 0xC9
                                             //Stack Pointer  0x04                  Program Couter                                            

int main()
{
    int a = 5;            //0x01
    int b = 6;            //0x02
    a = a - b;            //0x03

    tong(4,5);
    c = c - b;            //0x06
    tong(4,5);
    return 0;
}
//chương trình chạy từ 0x01 đến 0x03 thì gặp Hàm, địa chỉ tiếp theo là 0x04 sẽ được Stack Poiter lưu lại, Program Couter sẽ lấy địa chỉ của Hàm để đếm tiếp 0xC1 đến 0xC9
//sau khi chạy hết chương trình Program Couter vào Stack Poiter lấy địa chỉ đã lưu ban đầu vào chạy tiếp tức 0x04, Stack Poiter sẽ xóa giá trị 0x04
//tiếp đó Program Couter sẽ đếm tiếp dến 0x06 gặp tiếp Hàm thì Stack Poiter sẽ lưu 0x07, Program Couter sẽ lấy địa chỉ của Hàm để đếm tiếp 0xC1 đến 0xC9
//tương tự vậy cho đến khi kết thúc chương trình
