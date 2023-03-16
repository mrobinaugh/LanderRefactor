#include "Motor.h"

#include <array>
#include <cmath>

std::array<double, 3> Motor::getForce(double timeStep, double time, double angle){
    double forceMaginitude = getForceMagnitude(timeStep, time);
    
}

double getForceMagnitude(double timeStep, double time){
    double previousTime = time - timeStep;
    double currentForce = 15;
    double prevForce = 15;
    double averageForceMagnitude = (currentForce + prevForce) / timeStep;
    return averageForceMagnitude;
}