#include <stdio.h>
#include <stdint.h>
//VD tran bo nho Stack
int foo(int x){
 printf("De quy khong gioi han\n");
 return foo(x);
}
int main()
{
  //cap phat dong
  uint8_t *ptr=malloc(5);
  uint8_t *ptr=(uint8_t*)malloc(5);
  ptr = (uint8_t *)realloc(ptr, 7 * sizeof(uint8_t));
  free(ptr);
  
  return 0;
}
