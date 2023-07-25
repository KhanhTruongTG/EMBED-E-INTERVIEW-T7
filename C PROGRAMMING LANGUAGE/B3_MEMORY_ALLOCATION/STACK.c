#include <stdio.h>
#include <stdint.h>

void tong(int a,int b)                          // biến input parameter -> lưu trong vùng nhớ stack
{
    int c;                                      // biến cục bộ -> lưu trong vùng nhớ stack
    c=a+b;
    printf("tong a va b: %d\n",a+b);
}
int main(){
    tong(1,9);
    tong(2,4);
    return 0;
}
