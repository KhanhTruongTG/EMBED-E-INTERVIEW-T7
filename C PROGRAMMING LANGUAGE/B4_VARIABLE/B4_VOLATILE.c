#include <stdio.h>
#include <stdint.h>

int test;              //volatile int test; -> thông báo compiler không được tối ưu biến này

int main()
{
  while(1){
    test = 10;         //test = readDataUART() -> sẽ quay lại chạy code này nếu đã khai báo volatile
    //compiler sẽ tối ưu kh chạy lại dòng code này
    A();
    B();
    C();

  }
  return 0;
}

