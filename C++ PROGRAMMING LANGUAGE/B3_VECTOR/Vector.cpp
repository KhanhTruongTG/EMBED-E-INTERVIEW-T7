#include <iostream>
#include <vector>

using namespace std;

//truyền vector vào hàm
void test(vector<int> v){
    v[0] = 10;
}                                       //không thay đổi được do chỉ truyền tham số

void test1(vector<int> &v){
    v[0] = 10;
}                                       //thay đổi được giá trị vì truyền tham trị 

vector<int> test2(){
    vector<int> v = {5, 8, 7};
    return v;
}                                       //hàm có kiểu trả về là vector

int main(){

    vector<int> v = {1, 5, 6};          //khai báo vector
    v[1] = 2;

    v.push_back(3);                     //thêm giá trị vào cuối vector

    v.pop_back();                       //xóa giá trị cuối của vector

    v.insert(v.begin() + 1, 7);         //chèn giá trị đến vị trí cần chèn        ten_vector.insert(ten_vector.begin() + vị trí cần chèn giá trị, giá trị cần chèn);

    v.erase(v.begin() + 1);             //xóa vị trí chèn

    v.clear();                          //xóa hết giá trị vector

    v = {8, 9, 10};                     //thay đổi giá trị
    


    /* for(int x : v){                  //for cải tiến
        cout<< x;
    } */
    for (uint8_t i = 0; i < v.size() ; i++){
        cout<< v[i]<< " ";                //hoặc cout<<v.at(i);
    }
    
    test(v);
    test1(v);

    return 0;
}
