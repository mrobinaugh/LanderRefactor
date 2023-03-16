#include "Lander.h"
#include <array>

Lander::Lander(std::array<double,3> initInertiaMatrix,
                std::array<std::array<double,3>, 4> initState){
    inertiaMatrix = initInertiaMatrix;
    state = initState;
}

void Lander::propagateState(double angle, double timeStep){
    Lander::time += timeStep;
    

    
}