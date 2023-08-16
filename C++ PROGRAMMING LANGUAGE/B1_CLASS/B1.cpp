#include <iostream>
#include <string>

using namespace std;

class SinhVien{
    public:
        int MSSV;                           //property
        string TEN;                         //property
        string LOP;                         //property
        int NAM_SINH;                       //property
        
        int TUOI(){                         //method
            return 2023 - NAM_SINH;
        }
        SinhVien(string ten, int nam_sinh, string lop){                         //constructor
            TEN = ten;
            LOP = lop;
            NAM_SINH = nam_sinh;
            static int id = 1000;
            MSSV = id;
            id++;
        }
        ~SinhVien(){}                                                          //destructor
            

};

void display(SinhVien sv){
    cout<<"MSSV: "<<sv.MSSV<<endl;
    cout<<"TEN: "<<sv.TEN<<endl;
    cout<<"LOP: "<<sv.LOP<<endl;
    cout<<"NAM SINH: "<<sv.NAM_SINH<<endl;
    cout<<"TUOI: "<<sv.TUOI()<<endl;
}


int main(){
    SinhVien sv1("Khanh", 2000, "CLC2B");                           //Class SinhVien, object sv1 

    /* sv1.MSSV = 1000;
    sv1.TEN = "Khanh";
    sv1.LOP = "CLC2B";
    sv1.NAM_SINH = 2000; */
    SinhVien sv2("Bien", 2000, "CLC2A");

    display(sv1);
    cout<<"---------------"<<endl;
    display(sv2);
    return 0;
}
