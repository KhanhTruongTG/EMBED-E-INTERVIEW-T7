/*  1. Thêm SV
    2. Cập nhập thông tin
    3. Xóa SV bằng ID
    4. Tìm kiếm SV theo tên
    5. Sắp xếp theo điểm TB
    6. Sắp xếp theo Tên
    7. Hiển thị danh sách SV
    0. Quay lại (đối với từng số đều phải có số 0) */

#include "SV.hpp"

int main(){
    vector<SinhVien> databaseSV;

    int key = 0;
    while(1){
        cout << "1. Thêm Sinh Viên\n";
        cout << "2. Cập nhật Thông Tin Sinh Viên\n";
        cout << "3. Xóa Sinh Viên\n";
        cout << "4. Tìm kiếm sinh viên theo tên \n";
        cout << "5. Sắp xếp sinh viên theo điểm trung bình\n";
        cout << "6. Sắp xếp sinh viên theo tên\n";
        cout << "7. Hiển thị danh sách sinh viên\n";
        cout << "0. Thoát chương trình\n";
        cout << "Nhập lựa chọn: ";
        cin >> key;
        string ten;
        switch(key){
        case 1:
            addSinhVien(databaseSV);
            break;
        case 2:
            int id;
            cout << "Nhập ID sinh viên cần cập nhật: ";
            cin >> id;
            updateSinhVien(databaseSV, id);
            break;
        case 3:
            int ID;
            cout << "Nhập ID sinh viên cần xóa: ";
            cin >> ID;
            delSinhVien(databaseSV,id);
            break;
        case 4:
            cout << "Nhập tên sinh viên cần tìm: ";
            cin >> ten;
            findSinhvien(databaseSV,ten);
            break;       
         case 5:
            sortTheoDiemTB(databaseSV);
            break;
        case 6:
            sortTheoTen(databaseSV);
            break;
         case 7:
            cout << "Danh sách sinh viên:\n";
            hienThi(databaseSV);
            break;
        case 0:
            cout << "Thoát chương trình\n";
            cout << "+--------------------------------+\n\n";
            return 0;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại\n";
            break;
        }
    }
    return 0;
}