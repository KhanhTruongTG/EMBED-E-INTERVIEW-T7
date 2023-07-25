#include <stdio.h>
#include <stdint.h>
#define SUM(a,b) a+b 
#define TEST abc

int main(){
    
    printf("tong a va b = %d\n", SUM(3,6));
    
    TEST;

    return 0;
}
//Macro định nghĩa gì thì nó sẽ thay thế vào code cái đó trong quá trình tiền xử lí
