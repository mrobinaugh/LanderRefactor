#include "Motor.h"
#include "Lander.h"

#include <array>
#include <cmath>

std::array<double, 3> Motor::getForce(Lander& lander, double timestep, std::array<double, 3> moments){

    double forceMaginitude = getForceMagnitude(timestep, lander.time);
    double forceX = std::acos(moments[1] / (lander.COM - lander.motorApplication));
    double forceY = std::acos(moments[0] / (lander.COM - lander.motorApplication));
    double forceZ = -std::sqrt(std::pow(forceMaginitude,2) - std::pow(forceY,2) 
                                            - std::pow(forceX,2));
}

double Motor::getForceMagnitude(double timeStep, double time){
    double previousTime = time - timeStep;
    double currentForce = 15;
    double prevForce = 15;
    double averageForceMagnitude = (currentForce + prevForce) / timeStep;
    return averageForceMagnitude;
}

std::array<double, 3> Motor::getTVCAngles(double forceX, double forceY, double forceMagnitude){
    double thetaX = std::acos(forceY/forceMagnitude);
    double thetaY = std::acos(forceX/forceMagnitude);
}