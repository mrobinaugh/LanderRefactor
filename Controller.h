#include <array>

class Controller{
public:
    static std::array<double,3> getCommandedMoment(std::array<std::array<double,3>, 4>);
};