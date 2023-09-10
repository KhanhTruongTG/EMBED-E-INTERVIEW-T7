/*
*File: DCM.cpp
*Author: Truong Huu Khanh
*Date: 10/9/2023
*Description: DC Motor controller system
*/

#include <iostream>
using namespace std;

typedef enum{
    CLOCKWISE,
    COUNTERCLOCKWISE
}Direction;

class DCMotor{
    private:
        double voltage;
        double maxCurrent;
        double speed;
        Direction direction;
        bool running;
    public:
        DCMotor(double voltage, double maxCurrent, double speed);
        void setSpeed(double speed);
        void setDirection(Direction direction);
        void start();
        void stop();
        bool isRunning();
};

DCMotor::DCMotor(double voltage, double maxCurrent, double speed){
    this->voltage = voltage;
    this->maxCurrent = maxCurrent;
    this->speed = speed;
    this->direction = Direction::CLOCKWISE;
    this->running = false;
}

void DCMotor::setSpeed(double speed){
    this->speed = speed;
}

void DCMotor::setDirection(Direction direction){
    this->direction = direction;
}

void DCMotor::start(){
    if(!running){
        running = true;
        cout << "Motor started." << endl;
    }
}

void DCMotor::stop(){
    if(running){
        running = false;
        cout << "Motor stopped." << endl;
    }
}

bool DCMotor::isRunning(){
    return running;
}

class FeedbackSystem{
    private:
        DCMotor& dcMotor;
    public:
        FeedbackSystem(DCMotor& motor):dcMotor(motor){}
        void checkOverload(double current, double maxCurrent);
        void checkOverheat(double temperature);
        void controllMotor(double current, double maxCurrent, double temperature);
};

void FeedbackSystem::checkOverload(double current, double maxCurrent){
    if(current > maxCurrent){
        cout << "Overload detected. Stopping motor." << endl;
        dcMotor.stop();
    }
}

void FeedbackSystem::checkOverheat(double temperature){
    if(temperature > 100.0){
        cout << "Overheat detected. Stopping motor." << endl;
        dcMotor.stop();
    }
}

void FeedbackSystem::controllMotor(double current, double maxCurrent, double temperature){
    dcMotor.start();
    dcMotor.setDirection(Direction::CLOCKWISE); 
    dcMotor.setSpeed(1000.0); 
    checkOverload(current, maxCurrent);
    checkOverheat(temperature);
}

/* code add khi có cảm biến
const double MAX_TEMPERATURE = 100.0;

class DCMotorController{
    private:
        DCMotor *motor;
        FeedbackSystem *feedback;
    public:
        DCMotorController(DCMotor *motor, FeedbackSystem *feedback){
            this->motor = motor;
            this->feedback = feedback;
        }
        void setSpeed(double speed) {
            this->motor->setSpeed(speed);
        }

        void setDirection(DCMotor::Direction direction) {
            this->motor->setDirection(direction);
        }

        void control() {
            double current = getCurrent();
            double temperature = getTemperature();

            this->feedback->detectOverload(current, this->motor->maxCurrent);
            this->feedback->detectOverheat(temperature, MAX_TEMPERATURE);

            if (this->feedback->isOverloaded() || this->feedback->isOverheated()) {
                this->motor->stop();
            }
            else {
                this->motor->start();
            }
        }

        double getCurrent() {
            // code to get current from sensors
            return 0.0;
        }

        double getTemperature() {
            // code to get temperature from sensors
            return 0.0;
        }
}; */

int main(){
    DCMotor dcMotor(13.0, 1.5, 0.0); 
    FeedbackSystem feedback(dcMotor);
    feedback.controllMotor(1.0, 1.4, 50.0); 
    return 0;
}


