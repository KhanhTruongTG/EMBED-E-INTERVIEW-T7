#include <iostream>
class DoiTuong{
    public:
      virtual char *cmd(){
        return (char *)"doi tuong\n";
      }
      void Display(){
        printf("%s",cmd());
      }
};
class SinhVien : public DoiTuong{
    char* cmd(){
        return (char *)"sinhvien\n";
    }
};
int main(){
  DoiTuong dt;
  dt.Display();
  SinhVien sv;
  sv.Display();
  return 0;
}

//Nếu không sử dụng virtual
//SinhVien kế thừa DoiTuong nên khi trỏ sv.Display thì sẽ trỏ đến hàm Display ở DoiTuong
//cmd() trong Display ở DoiTuong đang trỏ đến char *cmd()
//Nên khi ta gọi sv.Display thì cũng sẽ hiển thị nội dung trong vùng của class DoiTuong

//Nếu sử dụng virtual
//Khi gọi sv.Display, thì cmd() sẽ xem ở class SinhVien đã đã có ghi đè (override) hay chưa
//Lúc đó virtual char *cmd() sẽ kiểm tra xem cmd() ở SinhVien có định nghĩa lại hay không
//Nếu có thì nó sẽ load lại chương trình được định mới nhất (overload)
