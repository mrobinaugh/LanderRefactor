#include "Motor.h"
#include "Lander.h"

#include <array>
#include <cmath>

using namespace std;

array<double, 3> Motor::getForce(Lander& lander, double timestep, array<double, 3> moments){

    double forceMaginitude = getForceMagnitude(timestep, lander.time);
    double forceX = acos(moments[1] / (lander.COM - lander.motorApplication));
    double forceY = acos(moments[0] / (lander.COM - lander.motorApplication));
    double forceZ = -sqrt(pow(forceMaginitude,2) - pow(forceY,2) 
                                            - pow(forceX,2));
    array<double,3> forces = {forceX,forceY,forceZ};
    return forces;
}

double Motor::getForceMagnitude(double timeStep, double time){
    double previousTime = time - timeStep;
    double currentForce = 15;
    double prevForce = 15;
    double averageForceMagnitude = (currentForce + prevForce) / timeStep;
    return averageForceMagnitude;
}

array<double, 3> Motor::getTVCAngles(double forceX, double forceY, double forceMagnitude){
    double thetaX = acos(forceY/forceMagnitude);
    double thetaY = acos(forceX/forceMagnitude);
    double thetaZ = -acos(sqrt(1-pow(cos(thetaX),2)-pow(cos(thetaY),2)));
    return {thetaX,thetaY,thetaZ};
}