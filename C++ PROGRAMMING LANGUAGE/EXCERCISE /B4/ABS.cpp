#include <iostream>
using namespace std;

//WHEEL
class Wheel{
    private:
        int SPEED;
    public:
        Wheel(int speed = 0):SPEED(speed){}
        void SetSpeed(int speed);
        int GetSpeed() const;           //phương thức hằng (const method)
};

void Wheel::SetSpeed(int speed){
    SPEED = speed;
}
int Wheel::GetSpeed() const{            
    return SPEED;
}

//CAR
class Car{
    private:
        Wheel WHEEL;
        int WEIGHT;
    public:
        Car(int weight = 1000):WHEEL(), WEIGHT(weight){}
        void SetWeight(int weight);
        int GetWeight() const;
        void AddPassenger(int weight);
        int GetTotalWeight() const;
        const Wheel& GetWheel() const;
        Wheel& GetWheel();
};

void Car::SetWeight(int weight){
    WEIGHT = weight;
}

int Car::GetWeight() const{
    return WEIGHT;
}

void Car::AddPassenger(int weight){
    WEIGHT += weight;
}

int Car::GetTotalWeight() const{
    return WEIGHT;
}

const Wheel& Car::GetWheel() const{
    return WHEEL;
}

Wheel& Car::GetWheel(){
    return WHEEL;
}

//ABS
class ABS{
    private:
        Car& CAR;
        const int MIN_SPEED = 10;
        const int MAX_LIFT = 1000;
    public:
        ABS(Car& car):CAR(car){}
        void ApplyBrakes();
        void Adjust();
};

void ABS::ApplyBrakes(){
    if(CAR.GetWheel().GetSpeed() < MIN_SPEED){
        cout << "Cảnh báo phanh sẽ bị bó cứng\n";
        Adjust();
    }
    else{
        cout << "Phanh áp dụng OK\n";
    }
}

void ABS::Adjust(){
    int weight = CAR.GetTotalWeight();
    double lift = weight / MAX_LIFT;
    double brake_force = (1.0 - lift) * 1.0;
    cout << "Điều chỉnh phanh về " << brake_force << "\n";
}

int main(){
    Car car;
    ABS abs(car);
    car.GetWheel().SetSpeed(5.0);
    abs.ApplyBrakes();
    car.AddPassenger(70.0);
    car.GetWheel().SetSpeed(15.0);
    abs.ApplyBrakes();
    return 0;
}
