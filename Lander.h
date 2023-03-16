#pragma once

#include <array>

class Lander{
    std::array<double,3> inertiaMatrix;
    std::array<std::array<double,3>,4> state;
    double time = 0.0;
    double gravity = -9.81;

public:
    Lander(std::array<double,3>, std::array<std::array<double,3>,4>);
    void propagateState(double, double);
};