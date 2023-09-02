#include <iostream>
template <typename var1, typename var2>
var1 tong(var1 a, var2 b){
  return var1(a+b);
}
int main(){
    printf("tong a va b la %f\n", tong(3,5.6));
    //var 1 sẽ có kiểu dữ liệu là int, var2 có kiểu dữ liệu là double
    //tong trả về kiểu var1 nên sẽ có kiểu dữ liệu là int
    return 0;
}
