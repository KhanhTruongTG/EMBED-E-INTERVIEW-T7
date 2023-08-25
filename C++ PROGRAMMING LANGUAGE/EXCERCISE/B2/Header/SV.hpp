#ifndef  __SV_H
#define  __SV_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef enum{
    GIOI,
    KHA,
    TB,
    YEU
}typeHocLuc;

typedef enum{
    NAM,
    NU
}typeGioiTinh;

class SinhVien{
    private:
        int ID;
        string TEN;
        int TUOI;
        typeGioiTinh GIOITINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
    public:
        SinhVien(string ten, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa);
        void setTen(string ten);
        void setTuoi(int tuoi);
        void setGioiTinh(typeGioiTinh gioitinh);
        void setDiemToan(double diem_toan);
        void setDiemLy(double diem_ly);
        void setDiemHoa(double diem_hoa);
        int getId();
        string getTen();
        int getTuoi();
        typeGioiTinh getGioiTinh();
        double getDiemToan();
        double getDiemLy();
        double getDiemHoa();
        double getDiemTb();
        typeHocLuc getHocLuc();
};

void addSinhVien(vector<SinhVien>& databaseSV);
void updateSinhVien(vector<SinhVien>& databaseSV, int id);
void delSinhVien(vector<SinhVien>& databaseSV, int id);
void findSinhvien(vector<SinhVien>& databaseSV, string ten);
void sortTheoDiemTB(vector<SinhVien>& databaseSV);
void sortTheoTen(vector<SinhVien>& databaseSV);
void hienThi(vector<SinhVien>& databaseSV);

#endif

