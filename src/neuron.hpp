#pragma once

#include <cassert>
#include <functional>
#include "vector.hpp"

class Neuron {
private:
    Vector weights;
    double bias;
    std::function<double(double)> activation;
public:
    Neuron(const Vector& weights, double bias, std::function<double(double)> activation) : weights(weights), bias(bias), activation(activation) {}

    double forward(const Vector& inputs) const {
        assert(weights.size() == inputs.size());
        return activation(weights * inputs + bias);
    }
};