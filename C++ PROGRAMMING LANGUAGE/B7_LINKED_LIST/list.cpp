#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> array = {1,6,5,7,8,4};
    list<int>::iterator it;
    for (it = array.begin(); it != array.end(); ++it){
      //list<int>::iterator it là biến con trỏ khai báo theo kiểu interator (kiểu dữ liệu để lưu địa chỉ)
      //array.begin(): địa chỉ đầu tiền của list
      //array.end(): địa chỉ kế cuối của list
        if(*it = 6){
            array.erase(it);
            break;
        }
    }
    for (it = array.begin(); it != array.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}
