#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint8_t x[13];
    uint16_t y[15];
    uint32_t z[10];
    uint64_t k[3];      
}toaDo;

int main(){
  printf("size: %d\n", sizeof(toaDo));
  return 0;
}

/* lấy 1 member kiểu dữ liệu lớn nhất để quét
1 ô 1 byte uint8_t x[13] -> 
                    quét 1 8 byte (8 ô nhớ)
                    quét 2 8 byte (5 ô nhớ)              dư 3 byte đệm
1 ô 2 byte uint16_t y[15] -> 3 byte đệm quét được 1 lần (1 ô nhớ)         1 byte đệm (không quan tâm)
                    quét 1 8 byte (4 ô nhớ)
                    quét 2 8 byte (4 ô nhớ)
                    quét 3 8 byte (4 ô nhớ)
                    quét 4 8 byte (2 ô nhớ)              dư 4 byte đệm
1 ô 4 byte uint32_t z[10] -> 4 byte đệm quét được 1 lần (1 ô nhớ)
                    quét 1 8 byte (2 ô nhớ)
                    quét 2 8 byte (2 ô nhớ)
                    quét 3 8 byte (2 ô nhớ)
                    quét 4 8 byte (2 ô nhớ) 
                    quét 5 8 byte (1 ô nhớ)                               dư 4 byte đệm (không quan tâm)
1 ô 8 byte  uint64_t k[3]
                    quét 1 8 byte (1 ô nhớ)
                    quét 2 8 byte (1 ô nhớ)
                    quét 3 8 byte (1 ô nhớ)
=> Kích thước bộ nhớ của Struct = tổng byte các lần quét cộng lại 14*8 = 112 byte */
