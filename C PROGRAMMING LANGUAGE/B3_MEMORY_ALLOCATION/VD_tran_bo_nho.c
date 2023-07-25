#include <stdio.h>
#include <stdint.h>

//VD tran bo nho Stack
int foo(int x){
 printf("De quy khong gioi han\n");
 return foo(x);
}
int main()
{
  //VD tran bo nhơ Heap
  int *A = (int *)malloc(18446744073709551615);
  
  return 0;
}
