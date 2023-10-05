#include "Lander.h"
#include "Motor.h"

#include <array>
#include <cmath>

Lander::Lander(std::array<double,3> initInertiaMatrix,
                std::array<std::array<double,3>, 4> initState, double initMass){
    // Initialize inertia values                
    ix = initInertiaMatrix[0];
    iy = initInertiaMatrix[1];
    iz = initInertiaMatrix[2];

    // Initialize positional and rotational state
    thetax = initState[0][0];
    thetay = initState[0][1];
    thetaz = initState[0][2];
    wx = initState[1][0];
    wy = initState[1][1];
    wz = initState[1][2];
    x = initState[2][0];
    y = initState[2][1];
    z = initState[2][2];
    vx = initState[3][0];
    vy = initState[3][1];
    vz = initState[3][2];

    // Initialize mass
    mass = initMass;
}

void Lander::propagateState(double momentX, double momentY, double timeStep){
    Lander::time += timeStep;
    std::array<double,3> momentCommand = {momentX, momentY, 0.0};
    std::array<double,3> force = Motor::getForce(Lander::CG, Lander::motorApplication,
                                                    Lander::time, timeStep, momentCommand);
    double accelerationX = force[0] / Lander::mass;
    double accelerationY = force[1] / Lander::mass;
    double accelerationZ = (force[2] / Lander::mass) - 9.81;
    Lander::vx = Lander::vx + accelerationX * timeStep;
    Lander::vy = Lander::vy + accelerationY * timeStep;
    Lander::vz = Lander::vz + accelerationZ * timeStep;
    Lander::x = Lander::x + Lander::vx * timeStep + 0.5 * accelerationX * pow(timeStep, 2.0);
    Lander::y = Lander::y + Lander::vy * timeStep + 0.5 * accelerationY * pow(timeStep, 2.0);
    Lander::z = Lander::z + Lander::vz * timeStep + 0.5 * accelerationZ * pow(timeStep, 2.0);
    


    
}