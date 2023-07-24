#include <stdio.h>
#include <stdint.h>

typedef union{
    uint8_t x;
    uint16_t y[10];
    uint64_t k;      
}toaDo;

int main(){
  printf("size: %lu\n", sizeof(toaDo));
  return 0;
}



/* lấy member có kiểu dữ liệu lớn nhất để quét
1 ô nhớ 1 byte uint8_t x -> quét 1 8 byte (1 ô nhớ)             dư 7 byte đệm (không quan tâm) => tổng 8 byte
1 ô nhớ 2 byte uint16_t y[10] -> quét 1 8 byte (4 ô nhớ)
                                 quét 2 8 byte (4 ô nhớ)
                                 quét 3 8 byte (2 ô nhớ)        dư 4 byte đệm (không quan tâm) => tổng 24 byte
1 ô nhơ 8 byte uint64_t k -> quét 1 8 byte (1 ô nhớ)            => tổng 8 byte
=> So sánh 3 member thì uint16_t y[10] lớn nhất nên kích thước bộ nhớ Union là 24 byte */


