#include "Motor.h"
#include "Lander.h"

#include <array>
#include <cmath>

using namespace std;

array<double, 3> Motor::getForce(double CG, double motorApplication, double time, double timestep, array<double, 3> moments){

    double forceMaginitude = getForceMagnitude(timestep, time);
    double forceX = moments[1] / (CG - motorApplication);
    double forceY = moments[0] / (CG - motorApplication);
    double forceZ = sqrt(pow(forceMaginitude,2) - pow(forceY,2) 
                                            - pow(forceX,2));
    array<double,3> forces = {forceX,forceY,forceZ};
    return forces;
}

double Motor::getForceMagnitude(double timeStep, double time){
    double previousTime = time - timeStep;
    double currentForce = 15;
    double prevForce = 15;
    double averageForceMagnitude = (currentForce + prevForce) / 2;
    return averageForceMagnitude;
}

array<double, 3> Motor::getTVCAngles(double forceX, double forceY, double forceMagnitude){
    double thetaX = acos(forceY/forceMagnitude);
    double thetaY = acos(forceX/forceMagnitude);
    double thetaZ = -acos(sqrt(1-pow(cos(thetaX),2)-pow(cos(thetaY),2)));
    return {thetaX,thetaY,thetaZ};
}