#include "date.h"

const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};                     //lưu các tên thứ trong tuần cách 1

//const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};         //lưu các tên thứ trong tuần cách 2

int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};                                                 //lưu số ngày trong tháng

//điều kiện năm nhuần
int leapYear(uint16_t year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//kiểm tra ngày hợp lệ
bool validDate(int day, int month, int year){
    if (year < 0) {
        return false; //năm không hợp lệ
    }

    if (month < JANUARY || month > DECEMBER){
        return false; //tháng không hợp lệ
    }

    if (leapYear(year)) {
        daysInMonth[2] = 29; //nếu năm nhuận thì tháng 2 có 29 ngày
    }

    if (day < 1 || day > daysInMonth[month]){
        return false; //ngày không hợp lệ
    }

    return true;
}

//các ngày trong tuần
int dayOfWeek(int day, int month, int year){

    //công thức chọn thứ cách 1
    if (leapYear(year)){
        daysInMonth[2] = 29;
    }

    int totalDays = 0;      //tính tổng ngày
    for (int i = 1; i < month; i++){     
        totalDays += daysInMonth[i];
    }
    totalDays += day;
               
    int daysOfWeek = (totalDays + (year - 1) + (year - 1)/4 - (year - 1)/100 + (year - 1)/400) % 7;
    return daysOfWeek;

    /* //công thức chọn thứ cách 2
    if (leapYear(year)){
        daysInMonth[2] = 29;
        int daysOfWeek = (day + 2*month + year + (3*(month + 1))/5 + (year/4)) % 7;
        daysOfWeek += 2;
        return daysOfWeek;
    }

    int daysOfWeek = (day + 2*month + year + (3*(month + 1))/5 + (year/4)) % 7;        
    return daysOfWeek; */
}
