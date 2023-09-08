#include<iostream>
#include<map>
#include<string>
using namespace std;

typedef struct{
    string name;
    int age;
}Infor;


int main(){
    map<int, Infor> Student;
    Student[100] = Infor{"Hoang", 20}; 
    Student[101] = Infor{"Khanh", 24};
    Student[102] = Infor{"Bien", 23};
    for(auto item : Student){
        cout << endl << "ID = " << item.first << ", Name: " << item.second.name << ", age: " << item.second.age << endl;
    }
    return 0;
}
