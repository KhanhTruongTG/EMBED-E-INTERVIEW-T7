#include <stdio.h>
#include <stdint.h>

typedef union{
    uint8_t  x[13];
    uint16_t y[15];
    uint32_t z[10];
    uint64_t k[3];      
}toaDo;

int main(){
  printf("size: %d\n", sizeof(toaDo));
  return 0;
}

