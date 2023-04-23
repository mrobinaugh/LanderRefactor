#include "Lander.h"
#include "Controller.h"
#include <array>

int main () {
    std::array<double,3> inertiaMatrix = {1.0,1.0,1.0};
    std::array<double,3> initRotationalPosition = {0.0,0.0,0.0};
    std::array<double,3> initRotationalVelocity = {0.0,0.0,0.0};
    std::array<double,3> initVelocity = {0.0,0.0,0.0};
    std::array<double,3> initPoisiton = {0.0,0.0,5.0};
    std::array<std::array<double,3>,4> initRotationalState = {initRotationalPosition,
                                                                initRotationalVelocity,
                                                                initVelocity,
                                                                initPoisiton};
    double initMass = 1.0;
    
    Lander lander(inertiaMatrix, initRotationalState, initMass);

    return 0;
}

void mainLoop(Lander lander){
    double timeStep = 0.02;
    while(lander.state[3][2] > 0){
        double momentX = Controller::getCommandedMoment(lander.inertiaMatrix[0],lander.state[0][0],lander.state[1][0]);
        double momentY = Controller::getCommandedMoment(lander.inertiaMatrix[0],lander.state[0][1],lander.state[1][1]);
        lander.propagateState(momentX, momentY, timeStep);
    }

}