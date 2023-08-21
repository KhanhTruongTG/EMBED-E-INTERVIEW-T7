#include <iostream>
#include <string>

using namespace std;

//Inheritance (Tính kế thừa)
class DoiTuong{
    protected:
        string TEN;
        int TUOI;
    public:
        void nhapThongTin(string ten, int tuoi);
        void hienThi();
};

void DoiTuong::nhapThongTin(string ten, int tuoi){
    this->TEN = ten;
    this->TUOI = tuoi;
}

void DoiTuong::hienThi(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;
}

class SinhVien: public DoiTuong{
    private:
        int MSSV;
    public:
        void nhapThongTin(string ten, int tuoi, int mssv);
        void hienThi();
};

void SinhVien::nhapThongTin(string ten, int tuoi, int mssv){
    this->TEN = ten;
    this->TUOI = tuoi;
    this->MSSV = mssv;
}

void SinhVien::hienThi(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;
    cout<<"MSSV: "<<MSSV<<endl;
}

int main(){
    DoiTuong dt;
    dt.nhapThongTin("Khanh", 23);
    dt.hienThi();

    SinhVien sv;
    sv.nhapThongTin("Bien", 23, 1000);
    sv.hienThi();
    

    return 0;
}
