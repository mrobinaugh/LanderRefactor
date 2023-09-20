#pragma once

#include <array>

class Motor{
private:
    static double getForceMagnitude(double, double);
public:
    static std::array<double, 3> getForce(double, double, double, double, std::array<double, 3>);
    static std::array<double, 3> getTVCAngles(double, double, double);
};