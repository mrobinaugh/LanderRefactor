#pragma once

#include <array>

class Motor{
public:
    std::array<double, 3> getForce(double, double, double);
};