#pragma once

#include <array>

class Motor{
public:
    std::array<double, 3> getForce(Lander&, double, std::array<double, 3>);
    double getForceMagnitude(double, double);
    std::array<double, 3> getTVCAngles(double, double, double);
};