#include<stdio.h>
#include<stdint.h>

int test(void)
{
   static int x = 0; //compiler sẽ bỏ qua và không khởi tạo biến x lại lần nữa khi gặp dòng code này
   x = x + 1;
   printf("%d\r\n",x);
} 
 
int main() {
   test ();         //giá trị của x tăng lên 1 đơn vị từ 0
   test ();         //giá trị của x tăng lên 1 đơn vị từ 1
   test ();         //giá trị của x tăng lên 1 đơn vị từ 2
   test ();         //giá trị của x tăng lên 1 đơn vị từ 3
  
   return 0;
}
