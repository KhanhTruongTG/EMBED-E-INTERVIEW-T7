#include <stdio.h>
#include <stdint.h>
// bien
uint8_t var;          //0 -> 2^8-1
int8_t a;             //(-2^8)/2 -> (2^8)/2-1
uint16_t var1;
int16_t b;
uint32_t var2;
int32_t c;
uint64_t var3;
int64_t d;

// typedef
typedef int typeInt;

//ham
void tong(int a, int b){
  printf("tong %d va %d = %d\n", a, b, a+b);

}

//struct
struct toaDo{
  uint8_t x;
  uint8_t y;
};

typedef struct toaDo{
  uint8_t x;
  uint8_t y;
}diemM;


int main()
{
  //cau dieu kien
  for(uint8_t i=0; i < 10; i++){
    printf("i = %d\n",i);
  }

  int i=0;
  while(i<10){
    printf("i = %d\n",i);
    i++;
  }

  do
  {
    printf("i = %d\n",i);
  } while (i<10);
  
  int diem = 8;
  if(diem >= 7){
    printf("hoc sinh kha\n");
  }else if(diem >=8){
    printf("hoc sinh gioi\n");
  }else{
    printf("hoc sinh TB\n");
  }

  int thu;
  switch (thu)
  {
  case 1:
    printf("thu 2\n");
    break;
  case 2:
    printf("thu 3\n");
    break;
  default:
    break;
  }
  
  return 0;
}
