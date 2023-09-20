#include "Lander.h"
#include "Motor.h"
#include <array>

Lander::Lander(std::array<double,3> initInertiaMatrix,
                std::array<std::array<double,3>, 4> initState, double initMass){
    inertiaMatrix = initInertiaMatrix;
    state = initState;
    mass = initMass;
}

void Lander::propagateState(double momentX, double momentY, double timeStep){
    Lander::time += timeStep;
    std::array<double,3> momentCommand = {momentX, momentY, 0.0};
    std::array<double,3> force = Motor::getForce(Lander::CG, Lander::motorApplication,
                                                    Lander::time, timeStep, momentCommand);
    double accelerationX = force[0] * Lander::mass;
    double accelerationY = force[0] * Lander::mass;
    double accelerationZ = (force[0] * Lander::mass) - 9.81;
    Lander::state[2][0] = Lander::state[2][0] + accelerationX * timeStep;
    Lander::state[2][1] = Lander::state[2][1] + accelerationY * timeStep;
    Lander::state[2][2] = Lander::state[2][2] + accelerationZ * timeStep;
    //Lander::state[3][0] = Lander::state[3][0] + Lander::state[2][0] * timeStep + 0.5 * accelerationX * timeStep ^ 2;
    //Lander::state[3][1] = Lander::state[3][1] + Lander::state[2][1] * timeStep + 0.5 * accelerationY * timeStep ^ 2;
    //Lander::state[3][2] = Lander::state[3][2] + Lander::state[2][2] * timeStep + 0.5 * accelerationZ * timeStep ^ 2;
    


    
}