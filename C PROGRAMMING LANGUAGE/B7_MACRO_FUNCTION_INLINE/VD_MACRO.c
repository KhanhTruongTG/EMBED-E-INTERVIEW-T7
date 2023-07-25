#include <stdio.h>
#include <stdint.h>


/* #ifndef STM32   //-> kiểm tra các định nghĩa đã được định nghĩa chưa. Nếu chưa thì thực hiện đoạn code, nếu có thì bỏ qua đoạn code
int a = 10;
#endif */


/* #define SIZE 40
#if SIZE > 20 
int a =30;
#elif SIZE == 20
int a= 10;
#else
int a=5;
#endif
//-> kiểm tra các điều kiện định nghĩa, định nghĩa thuộc điều kiện nào thì thực hiện code của điều kiện đó */



//VD1 về kiểm tra điều kiện trong thực tế
/* #define STM32    0
#define PIC16F   1
#define ATMGE    2

typedef enum{
  LOW,
  HIGH
}Status;

typedef enum{
  PIN0 << 0,
  PIN1 << 1
}Pins;

#if   MCU == STM32
void digitalWrite(Pins pin, Status status){
  DAC| pin ~status;
}
#elif MCU == PIC16F
void digitalWrite(Pins pin, Status status){
  CTO| pin ~status;
}
#elif MCU==ATMGE
void digitalWrite(Pin pin, Status status){
  MBC | pin-ASC ~status;
}
#endif
//-> đoạn code trên sẽ nằm trong file thư viện config.h

#define MCU STM32  //định nghĩa MCU theo các option trên
#include"config.h"
int main(){ 
while (1)
    {
      digitalWrite(PIN0,HIGH);
    }
  return 0;
}
 */



//VD2 định nghĩa nhiều hàng (sử dụng \(trừ dòng cuối của đoạn code))
/* #define CREATE_FUNC(funname, cmd)                                    \
void funname(){                                                      \
  printf(#cmd);  //-> xài # để cmd được hiểu như là 1 chuỗi          \
}

CREATE_FUNC(funA,This is funname A\n);
CREATE_FUNC(funB,"This is funname B");
int main(){
  funA();
  funB();
  return 0;
} */


//VD3 về nối chuỗi 
/* #define FUNC(type, name)                              \
  type var1##_name;  //-> sử dụng ## để nối chuỗi     \
  type var2##_name;                                   \
  type var3##_name;

int main(int argc, char const *argv[])
{
  FUNC(int,test);
  return 0;
} */

//VD4 về __VA_ARGS__ (khởi tạo nhiều tham số)
/* #define FUNC( ...)  __VA_ARGS__  //hoặc #define FUNC(name, ...)  \
                                    //      int name;                \  //-> tham số đầu tiên sẽ có kiểu int
                                    //      __VA_ARGS__
int main(){
  FUNC(test, "hello", 99);   //có nội dung gì thì __VA_ARGS__ sẽ in ra nội dung đó
  return 0;
}
 */














