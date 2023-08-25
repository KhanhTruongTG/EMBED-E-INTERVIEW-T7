#include "SV.hpp"

SinhVien::SinhVien(string ten, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa){
    static int id  = 1000;
    this->ID = id;
    id++;
    this->TEN = ten;
    this->TUOI = tuoi;
    this->GIOITINH = gioitinh;
    this->DIEM_TOAN = diem_toan;
    this->DIEM_LY = diem_ly;
    this->DIEM_HOA = diem_hoa;
}

void SinhVien::setTen(string ten){
    TEN = ten;
}

void SinhVien::setTuoi(int tuoi){
    TUOI = tuoi;
}

void SinhVien::setGioiTinh(typeGioiTinh gioitinh){
    GIOITINH = gioitinh;
}

void SinhVien::setDiemToan(double diem_toan){
    DIEM_TOAN = diem_toan;
}

void SinhVien::setDiemLy(double diem_ly){
    DIEM_LY = diem_ly;
}

void SinhVien::setDiemHoa(double diem_hoa){
    DIEM_HOA = diem_hoa;
}

int SinhVien::getId(){
    return ID;
}

string SinhVien::getTen(){
    return TEN;
}
int SinhVien::getTuoi(){
    return TUOI;
}

typeGioiTinh SinhVien::getGioiTinh(){
    return GIOITINH;
}

double SinhVien::getDiemToan(){
    return DIEM_TOAN;
}

double SinhVien::getDiemLy(){
    return DIEM_LY;
}

double SinhVien::getDiemHoa(){
    return DIEM_HOA;
}

double SinhVien::getDiemTb(){
    return (DIEM_TOAN + DIEM_LY + DIEM_HOA)/3;
}

typeHocLuc SinhVien::getHocLuc(){
    if (getDiemTb() >= 8) return GIOI;
    else if (getDiemTb() >= 6.5) return KHA;
    else if (getDiemTb() >= 5) return TB;
    else return YEU;
}



void addSinhVien(vector<SinhVien>& databaseSV){
    cout << "Nhập tên: ";
    string ten;
    cin.ignore();
    getline(cin, ten);

    int tuoi;
    while(1){
        cout << "Nhập tuổi: ";
        cin >> tuoi;
        if (tuoi > 10 && tuoi < 1000) break;
        else cout << "Tuổi không hợp lệ\n";
    }

    cout << "0.NAM\n1.NU\nChọn giới tính (0 hoặc 1): ";
    typeGioiTinh gioitinh;
    int key = 0;
    cin >> key;
    switch(key){
        case 0:
            gioitinh = NAM;
            break;
        case 1:
            gioitinh = NU;
            break;
        default:
            break;
    }

    double diem_toan;
    while(1){
        cout << "Nhập điểm Toán: ";
        cin >> diem_toan;
        if (diem_toan >= 0 && diem_toan <= 10) break;
        else cout << "Điểm không hợp lệ\n";
    }

    double diem_ly;
    while(1){
        cout << "Nhập điểm Lý: ";
        cin >> diem_ly;
        if (diem_ly >= 0 && diem_ly <= 10) break;
        else cout << "Điểm không hợp lệ\n";
    }

    double diem_hoa;
    while(1){
        cout << "Nhập điểm Hóa: ";
        cin >> diem_hoa;
        if (diem_hoa >= 0 && diem_hoa <= 10) break;
        else cout << "Điểm không hợp lệ\n";
    }

    SinhVien sv = {ten, tuoi, gioitinh, diem_toan, diem_ly, diem_hoa};
    databaseSV.push_back(sv);
    cout << "\nNhập thông tin sinh viên thành công !!!\n";
    cout << "+--------------------------------+\n\n"; 
}

void updateSinhVien(vector<SinhVien>& databaseSV, int id){
    for(int i = 0; i < databaseSV.size(); i++){
        if(databaseSV[i].getId() == id){
            cout << "Nhập thông tin mới cho sinh viên có ID " << id << endl;
            string ten;
            int tuoi;
            typeGioiTinh gioitinh;
            int gioitinhUp;
            double diem_toan, diem_ly, diem_hoa;

            cout << "Tên: ";
            cin >> ten;
            cout << "Tuổi: ";
            cin >> tuoi;
            cout << "Giới tính (0: Nam, 1: Nữ): ";
            cin >> gioitinhUp;
            gioitinh = (gioitinhUp == 0) ? NAM : NU;
            cout << "Điểm Toán: ";
            cin >> diem_toan;
            cout << "Điểm Lý: ";
            cin >> diem_ly;
            cout << "Điểm Hóa: ";
            cin >> diem_hoa;

            databaseSV[i].setTen(ten);
            databaseSV[i].setTuoi(tuoi);
            databaseSV[i].setGioiTinh(gioitinh);
            databaseSV[i].setDiemToan(diem_toan);
            databaseSV[i].setDiemLy(diem_ly);
            databaseSV[i].setDiemHoa(diem_hoa);

            cout << "\nCập nhật thành công!\n";
            return;
        }
        else if(databaseSV[i].getId() != id){
            cout << "\nKhông tìm thấy ID\n";
            break; 
        }
    }
    cout << "+--------------------------------+\n\n";   
}

void delSinhVien(vector<SinhVien>& databaseSV, int id){
    for(auto i=databaseSV.begin();i!=databaseSV.end(); ++i){
        if(i->getId() == id){
            databaseSV.erase(i);
            cout << "\nXóa thành công\n";
            cout << "+--------------------------------+\n\n";
            return;
        }
    }
    
}

void findSinhvien(vector<SinhVien>& databaseSV, string ten){
    int find = 0;
    for(int i = 0; i < databaseSV.size(); i++){
        if(ten == databaseSV[i].getTen()){
            cout << "\t-----------------------------------------------------------------\t\n";
            cout << "\t|\t" << databaseSV[i].getId() << "\t|\t" << databaseSV[i].getTen() << "\t|\t" << databaseSV[i].getTuoi() << "\t|\t" << databaseSV[i].getDiemTb() << "\t|\t\n";
            cout << "\t-----------------------------------------------------------------\t\n";
            find++;
            return;
        }
    }
    if(find == 0){
        cout << "\nKhông tìm thấy Tên\n";
    }
    cout << "+--------------------------------+\n\n"; 
}

void sortTheoDiemTB(vector<SinhVien>& databaseSV){
    for(int i = 0; i < databaseSV.size() - 1; i++){
        for(int j = i + 1; j < databaseSV.size(); j++){
            if(databaseSV[i].getDiemTb() < databaseSV[j].getDiemTb()){
                swap(databaseSV[i], databaseSV[j]);
            }
        }
    }
    cout << "\nSắp xếp thành công\n";
    cout << "+--------------------------------+\n\n";
}

void sortTheoTen(vector<SinhVien>& databaseSV){
    for(int i = 0; i < databaseSV.size() - 1; i++){
        for(int j = i + 1; j < databaseSV.size(); j++){
            if(databaseSV[i].getTen() > databaseSV[j].getTen()){
                swap(databaseSV[i], databaseSV[j]);
            }
        }
    }
    cout << "\nSắp xếp thành công\n";
    cout << "+--------------------------------+\n\n";
}

void hienThi(vector<SinhVien>& databaseSV){
    cout << "\t-----------------------------------------------------------------\t\n";
    cout << "\t|\tID\t|\tTen\t|\tTuoi\t|\tDiem TB\t|\t\n";
    for (int i = 0; i < databaseSV.size(); i++){
        cout << "\t-----------------------------------------------------------------\t\n";
        cout << "\t|\t" << databaseSV[i].getId() << "\t|\t" << databaseSV[i].getTen() << "\t|\t" << databaseSV[i].getTuoi() << "\t|\t" << databaseSV[i].getDiemTb() << "\t|\t\n";
    }
    cout << "\t-----------------------------------------------------------------\t\n";  
}
