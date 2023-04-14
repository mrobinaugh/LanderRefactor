#include "Lander.h"
#include "Motor.h"
#include <array>

Lander::Lander(std::array<double,3> initInertiaMatrix,
                std::array<std::array<double,3>, 4> initState){
    inertiaMatrix = initInertiaMatrix;
    state = initState;
}

void Lander::propagateState(std::array<double,3> moments, double timeStep){
    Lander::time += timeStep;
    std::array<double,3> force = Motor::getForce(, timeStep, moments);

    
}