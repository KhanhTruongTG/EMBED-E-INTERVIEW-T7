/*
*File: GPS.cpp
*Author: Truong Huu Khanh
*Date: 7/9/2023
*Description: Distance between two GPS
*/

#include <iostream>
#include <math.h>
#define EARTH_RADIUS 6371.0
using namespace std;

class GPSPoint{
    private:
        double latitude;
        double longitude;
    public:
        GPSPoint(double lat, double lon):latitude(lat), longitude(lon){};
        void input();
        bool isValid();
        double toRadians(double degrees);
        double distanceTo(const GPSPoint& point);
};

void GPSPoint::input(){
    cout << "Latitude của GPS: ";
    cin >> latitude;
    while(!isValid()){
        cout << "Latitude không hợp lệ. Latitude nằm trong khoảng [-90, 90]. Nhập lại: ";
        cin >> latitude;
    }
    cout << "Longitude của GPS: ";
    cin >> longitude;
    while(!isValid()){
        cout << "Longitude không hợp lệ. Longitude nằm trong khoảng [-180, 180]. Nhập lại: ";
        cin >> longitude;
    }
}

bool GPSPoint::isValid(){
    return(latitude >= -90.0 && latitude <= 90.0) && (longitude >= -180.0 && longitude <= 180.0);
}

double GPSPoint::toRadians(double degrees){
    return degrees * M_PI / 180.0;
}

double GPSPoint::distanceTo(const GPSPoint& point){
    double lat1 = toRadians(latitude);
    double lat2 = toRadians(point.latitude);
    double deltaLat = toRadians(point.latitude - latitude);
    double deltaLon = toRadians(point.longitude - longitude);
    double a = sin(deltaLat / 2) * sin(deltaLat / 2) + cos(lat1) * cos(lat2) * sin(deltaLon / 2) * sin(deltaLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int main(){
    GPSPoint point1(0, 0);
    GPSPoint point2(0, 0);
    cout << "Nhập tọa độ điểm thứ nhất:\n";
    point1.input();
    cout << "Nhập tọa độ điểm thứ hai:\n";
    point2.input();
    double distance = point1.distanceTo(point2);
    cout << "Khoảng cách giữa hai GPS: " << distance << " km" << endl;
    return 0;
}
