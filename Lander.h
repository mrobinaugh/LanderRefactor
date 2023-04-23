#pragma once

#include <array>

class Lander{
    double gravity = -9.81;
    double mass;
public:
    std::array<double,3> inertiaMatrix;
    std::array<std::array<double,3>,4> state;
    double time = 0.0;
    double CG = 0.05;
    double motorApplication = 0.01;
    Lander(std::array<double,3>, std::array<std::array<double,3>,4>, double);
    void propagateState(double, double, double);
};