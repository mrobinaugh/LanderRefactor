#include <array>

#include "Controller.h"


double Controller::getCommandedMoment(double inertia, double theta, double omega){
    double kp = 1;
    double kd = 1;
    double thetaDesired = 0.0;
    double thetaCommand = thetaDesired - theta;
    double omegaCommand = thetaCommand * kp - omega;
    double alphaDesired = omegaCommand * kd;
    double momentCommand = alphaDesired * inertia;
    return momentCommand;
}