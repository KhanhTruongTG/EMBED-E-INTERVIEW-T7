#include <stdio.h>
#include <stdint.h>
#include "B6_test.c"

#define SIZE 20
#define SUM(a,b) a+b

int var = 10;

int main()
{
  //day la chu thich
  int arr[SIZE];
  test();
  
  printf("tong a + b = %d\n", SUM(5,6));
  return 0;
}
