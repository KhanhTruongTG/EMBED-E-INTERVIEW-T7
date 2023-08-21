#include <iostream>
#include <string>

using namespace std;

//Polymorphism (Tính đa hình)
class Toan{
    public:
        void tong(int a, int b){
            cout<<"tong a, b: "<<a+b<<endl;
        }
        void tong(int a, int b, int c){
            cout<<"tong a, b, c: "<<a+b+c<<endl;
        }
};

int main(){
    Toan Tong;

    Tong.tong(12, 3);
    Tong.tong(13,4,3);

    return 0;
}
