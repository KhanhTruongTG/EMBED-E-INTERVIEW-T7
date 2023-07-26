#include <stdio.h>

void tong (int a, int b){
    printf("tong a va b: %d\n",a+b);
}

int main()
{
    int a = 5;
    int b = 6;
    a = a-b;

    tong(9,5);
    tong(6,4);

    return 0;
}
