#pragma once

#include <algorithm>

class Activation {
public:
    static double relu(double input) {
        return std::max(0.0, input);
    }
};