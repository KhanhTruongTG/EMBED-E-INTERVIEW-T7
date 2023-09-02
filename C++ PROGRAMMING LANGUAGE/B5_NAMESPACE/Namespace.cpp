#include <iostream>
using namespace std;
using namespace ConOngA;
namespace ConOngA{
  int Teo = 10;
}
namespace ConOngB{
    int Teo = 20;
}
int main(){
    cout << Teo << endl;            //cách gọi khi using namespace ConOngA
    //dòng này sẽ bị lỗi nếu sử dụng cả 2 using namespace ConOngA và using namespace ConOngB
    //-> vì nó không hiểu đang gọi Teo trong namespace nào
    cout << ConOngB::Teo << endl;   //cách gọi thủ công
    return 0;
}
