#include <stdio.h>
#include <stdint.h>

void tong(int a, int b){
  printf("tong %d va %d = %d\n", a, b, a+b);
}
int main()
{
  //con tro
  int a = 10;
  int *ptr=&a;
	printf("dia chi a %p\n",&a);
	printf("gia tri ptr %p\n",ptr);
	printf("gia tri cua dia chi :d\n",*ptr);

  //con tro void
  int n;
  float f;
  double d;

  void *ptr1;
  ptr1 = &n; // ok
  ptr1 = &f; // ok
  ptr1 = &d; // ok

  //con tro ham
  void (*ptr2)(int,int);
  ptr2 = &tong;
  ptr2(9,7);

  //con tro NULL
  int* ptr3 = NULL;

  //con tro cap 2
  int var = 100;
  int *ptr4 = &var;      //tro den dia chi cua bien var
  int **p_to_p = &ptr4;    //tro den dia chi cua con tro ptr4

  return 0;
}
