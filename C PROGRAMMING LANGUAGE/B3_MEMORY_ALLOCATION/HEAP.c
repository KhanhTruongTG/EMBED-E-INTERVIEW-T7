#include <stdio.h>
#include <stdint.h>

int main(){
//cap phat dong
  uint8_t *ptr=malloc(5);
  uint8_t *ptr=(uint8_t*)malloc(5);
  ptr = (uint8_t *)realloc(ptr, 7 * sizeof(uint8_t));
  free(ptr);

//cấp phát động tạo ra vùng nhớ -> lưu trong vùng nhớ Heap
  return 0;
}
