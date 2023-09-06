#include <iostream>
#include <list>
#include <string>
using namespace std;
                                        
#define THAO_TAC(content)                                           \
    do{                                                             \
        content                                                     \
        printf("- Nhan phim '0' => De Thoat chuc nang\n");          \
        printf("- Nhan phim '1' => De tiep tuc chuc nang\n");       \
        printf("Nhan Phim: ");                                      \
        scanf("%d", &key);                                          \
    }while (key == 1);

typedef enum{
    NAM,
    NU
}typeSex;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}typeAbility;

class SV{
    private:
        string name;
        int age;
        typeSex sex;
        int id;
        float toan;
        float ly;
        float hoa;
        typeAbility hocluc;
    public:
        SV(string ten, int tuoi, typeSex gioitinh, float diemToan, float diemLy, float diemHoa);

        void setName(string ten);
        void setAge(int tuoi);
        void setSex(typeSex gioitinh);
        void setdiemToan(float diemToan);
        void setdiemLy(float diemLy);
        void setdiemHoa(float diemHoa);

        string getName();
        int getAge();
        typeSex getSex();
        float getToan();
        float getLy();
        float getHoa();
        int getID();
        float getAverage();
        string getHocluc();
};

SV::SV(string ten, int tuoi, typeSex gioitinh, float diemToan, float diemLy, float diemHoa){
    static int ID = 100;
    SV::id = ID;
    ID++;
    this->name = ten;
    this->age = tuoi;
    this->sex = gioitinh;
    this->toan = diemToan;
    this->ly = diemLy;
    this->hoa = diemHoa;
}

void SV::setName(string ten){
    name = ten;
}

void SV::setAge(int tuoi){
    age = tuoi;
}

void SV::setSex(typeSex gioitinh){
    sex = gioitinh;
}

void SV::setdiemToan(float diemToan){
    toan = diemToan;
}

void SV::setdiemLy(float diemLy){
    ly = diemLy;
}

void SV::setdiemHoa(float diemHoa){
    hoa = diemHoa;
}

string SV::getName(){
    return name;
}

int SV::getAge(){
    return age;
}

typeSex SV::getSex(){
    return sex;
}

float SV::getToan(){
    return toan;
}

float SV::getLy(){
    return ly;
}

float SV::getHoa(){
    return hoa;
}

int SV::getID(){
    return (int)id;
}

float SV::getAverage(){
    float avg = (toan + ly + hoa)/3;
    return avg;
}

string SV::getHocluc(){
    typeAbility HOCLUC;
    SV::hocluc = HOCLUC;
    if(getAverage() >= 8){
        HOCLUC == GIOI;
        return "GIOI";
    }
    else if (getAverage() >= 6.5){
        HOCLUC == KHA;
        return "KHA";
    }
    else if(getAverage() >= 5){
        HOCLUC == TRUNG_BINH;
        return "TRUNG_BINH";
    }
    else{
        HOCLUC == YEU;
        return "YEU";
    }
}

class MENU{
    private:
        list<SV> Database;
    public:
        void themSV();
        void capnhatSV();
        void xoaSV();
        void timkiemSV();
        void sapxepGPA();
        void sapxepTen();
        void danhsachSV();
};

void MENU::themSV(){
    cout<<"--THEM SINH VIEN--"<<endl;
    string ten;
    int tuoi;
    typeSex gioitinh;
    float toan, ly, hoa;
    int key;
    THAO_TAC
    (
    do{
        cin.ignore();
        cout<<"Nhap ten sinh vien: ";
        getline(std::cin, ten); 
    }while(ten.empty());
        

    do{
        cout<<"Nhap tuoi sinh vien: ";
        cin>>tuoi;
        cin.ignore();
    }while(tuoi < 0);
    
    int choiceSex;
    do{
        cout<<"Nhap gioi tinh '0. Nam - 1. Nu': ";
        cin>>choiceSex;
        cin.ignore();
    }while(choiceSex != 0 && choiceSex != 1);
    gioitinh = static_cast<typeSex>(choiceSex);

    do{
        cout<<"Nhap diem toan: ";
        cin>>toan;
        cin.ignore();
    }while(toan < 0 || toan > 10);

    do{
        cout<<"Nhap diem ly: ";
        cin>>ly;
        cin.ignore();
    }while(ly < 0 || ly > 10);

    do{
        cout<<"Nhap diem hoa: ";
        cin>>hoa;
        cin.ignore();
    }while(hoa < 0 || hoa > 10);

    SV newStudent(ten, tuoi, gioitinh, toan, ly, hoa);
    Database.push_back(newStudent);
    cout<<newStudent.getID()<<endl;
    cout<<"Them thanh cong"<<endl;
    cout<<"---------------"<<endl;
    );
}

void MENU::capnhatSV(){
    cout<<"--CAP NHAT THONG TIN SINH VIEN THEO MA ID--"<<endl;
    int id;
    string ten;
    int tuoi;
    typeSex gioitinh;
    float toan, ly, hoa;
    int key;
    int chonphim;
    bool haveSV = false;
    cout<<"Nhap ID sinh vien can cap nhat: ";
    cin>>id;
    THAO_TAC(
    for(SV &item : Database){   
        if(item.getID() == id){
            printf("--CHON THONG TIN CAN CAP NHAT--\n");
            printf("1. TEN\n");
            printf("2. TUOI\n");
            printf("3. GIOI TINH\n");
            printf("4. DIEM TOAN\n");
            printf("5. DIEM LY\n");
            printf("6. DIEM HOA\n");
            printf("7. Thoat\n");
            printf("-------------------------------------------\n");
            do{
                cout<<"Nhan phim: ";
                cin>>chonphim;
            }while(0);
            switch(chonphim){
            case 1:
                do{
                    cin.ignore();
                    cout<<"Nhap ten sinh vien: ";
                    getline(std::cin, ten); 
                }while(ten.empty());
                item.setName(ten);
                break;
            case 2:
                do{
                    cout<<"Nhap tuoi sinh vien: ";
                    cin>>tuoi;
                    cin.ignore();
                }while(tuoi < 0);
                item.setAge(tuoi);
                break;
            case 3:
                int choiceSex;
                do{
                    cout<<"Nhap gioi tinh '0. Nam - 1. Nu': ";
                    cin>>choiceSex;
                    cin.ignore();
                }while(choiceSex != 0 && choiceSex != 1);
                gioitinh = static_cast<typeSex>(choiceSex);
                item.setSex(gioitinh);
                break; 
            case 4: 
                do{
                    cout<<"Nhap diem toan: ";
                    cin>>toan;
                    cin.ignore();
                }while(toan < 0 || toan > 10);
                item.setdiemToan(toan);
                break;
            case 5:
                do{
                    cout<<"Nhap diem ly: ";
                    cin>>ly;
                    cin.ignore();
                }while(ly < 0 || ly > 10);
                item.setdiemLy(ly);
                break;
            case 6:
                do{
                    cout<<"Nhap diem hoa: ";
                    cin>>hoa;
                    cin.ignore();
                }while(hoa < 0 || hoa > 10);
                item.setdiemHoa(hoa);
                break;
            case 7:
                break;
            default:
                cout<<"Lua chon khong dung, vui long nhap lai!"<<endl;
                break;
            }
            haveSV = 1;
            break;
        }
    }
    if(haveSV != 1)  printf("Khong tim thay sinh vien co ma ID: %d\n", id);   
    );
}

void MENU::xoaSV(){
    int key;
    int id;
    bool haveSV = false;
    auto position = Database.begin();
    cout<<"--XOA SINH VIEN THEO MA ID--"<<endl;
    cout<<"Nhap ma ID cua sinh vien can xoa: ";
    cin>>id;
    THAO_TAC(
    for(auto item : Database){
        if(item.getID() == id){
            Database.erase(position);
            cout<<"Da xoa thanh cong sinh vien co ma ID: "<<id<<endl;
            haveSV = 1;
            break;
        }
        position++;
    }
    if(haveSV != 1) cout<<"Khong tim thay sinh vien"<<endl;
    ); 
}

void MENU::timkiemSV(){
    int key;
    bool haveSV = false;
    string ten;
    cout<<"--TIM KIEM SINH VIEN THEO TEN--"<<endl;
    cin.ignore();
    cout<<"Nhap ten sinh vien can tim kiem: ";
    getline(cin, ten);
    THAO_TAC(
        for(auto temp : Database){
            if(temp.getName().compare(ten) == 0){
                cout<< "ID: "<< temp.getID() <<endl;
                cout<< "TEN:"<< temp.getName() <<endl;
                cout<< "TUOI:"<< temp.getAge()<<endl;
                if(temp.getSex() == 0) cout<<"GIOI TINH: NAM"<<endl;
                else cout<<"GIOI TINH: NU"<<endl;
                cout<< "DIEM TOAN: "<< temp.getToan()<<endl;
                cout<< "DIEM LY: "<< temp.getLy()<<endl;
                cout<< "DIEM HOA: "<< temp.getHoa()<<endl;
                cout<< "DIEM TB: "<< temp.getAverage()<<endl;
                cout<< "HOC LUC: "<<temp.getHocluc()<<endl;
                cout<< "-------------------------------"<<endl;
                haveSV = 1;
            }
            break;
        }
        if(haveSV != 1) cout<<"Khong tim thay sinh vien phu hop!"<<endl;
        
    );
}

void swap(SV *sv1, SV *sv2){
    SV temp = *sv1;
    *sv1 = *sv2;
    *sv2 = temp;
}

void MENU::sapxepGPA(){
    int key;
    auto position = Database.begin();
    cout<<"--SAP XEP SINH VIEN THEO THU TU TANG DAN DIEM GPA--"<<endl;
    THAO_TAC(
        for (auto &temp : Database){
            SV *sv1 = &temp;
            for(auto &item : Database){
                SV *sv2 = &item;
                if(sv1->getAverage() > sv2->getAverage()){
                    swap(sv1, sv2);
                }
            }  
        }
    cout<<"Da sap xep thanh cong!"<<endl;    
    );
}

void MENU::sapxepTen(){
    int key;
    cout<<"--SAP XEP SINH VIEN THEO TEN--"<<endl;
    THAO_TAC(
        for (auto &temp : Database){
            SV *sv1 = &temp;
            for (auto &item : Database){
                SV *sv2 = &item;
                if(sv1->getName() > sv2->getName()){
                    swap(sv1, sv2);
                }
            }  
        }
    cout<<"Da sap xep thanh cong!"<<endl;    
    );
}

void MENU::danhsachSV(){
    int key;
    if(Database.empty()){
        cout<<"--DANH SACH SINH VIEN TRONG!--"<<endl;
    }else{
        THAO_TAC(
            cout<<"--DANH SACH SINH VIEN--"<<endl;
            for(SV temp : Database){
                cout<<"ID: "<<temp.getID()<<endl;
                cout<<"TEN: "<<temp.getName()<<endl;
                cout<<"TUOI: "<<temp.getAge()<<endl;
                if(temp.getSex() == 0) cout<<"GIOI TINH: NAM"<<endl;
                else cout<<"GIOI TINH: NU"<<endl;
                cout<<"DIEM TOAN: "<<temp.getToan()<<endl;
                cout<<"DIEM LY: "<<temp.getLy()<<endl;
                cout<<"DIEM HOA: "<<temp.getHoa()<<endl;
                cout<<"___________________________"<<endl;
            }
        );
    }
}

void program(){
    int temp;
    MENU menu;
    do{
        printf("------CHUONG TRINH QUAN LY SINH VIEN------\n");
        printf("1. Them Sinh Vien\n");
        printf("2. Cap nhat Thong Tin Sinh Vien\n");
        printf("3. Xoa Sinh Vien boi ID\n");
        printf("4. Tim kiem Thong Tin theo Ten \n");
        printf("5. Sap Xep Sinh Vien theo GPA\n");
        printf("6. Sap Xep Sinh Vien theo Ten\n");
        printf("7. Hien thi Danh Sach Sinh Vien\n");
        printf("8. Thoat\n");
        printf("-------------------------------------------\n");
        do{
            printf("Nhan Phim de tiep tuc: ");
            scanf("%d", &temp);
        }while(temp > 8 || temp < 1);
        switch(temp){
        case 1:
            menu.themSV();
            break;
        case 2:
            menu.capnhatSV();
            break;
        case 3:
            menu.xoaSV();
            break;
        case 4:
            menu.timkiemSV();
            break;
        case 5:
            menu.sapxepGPA();
            break;
        case 6:
            menu.sapxepTen();
            break;
        case 7:
            menu.danhsachSV();
            break;
        case 8:
            exit(0);
        default:
            break;
        }
    }while(1);
}

int main(){
    program();
    return 0;
}
