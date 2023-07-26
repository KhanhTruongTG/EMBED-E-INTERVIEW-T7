#include <stdio.h>
#include <stdint.h>
void tong (int a, int b){
    printf("tong a va b: %d\n",a+b);
}

int main()
{
    int a = 5;
    int b = 6;
    a = a-b;

    tong(4,5);
    tong(2,4);

    return 0;
}
