#pragma once

#include <functional>
#include "vector.hpp"
#include "activation.hpp"

class Neuron {
private:
    Vector weights;
    double bias;
    std::function<double(double)> activation;
public:
    Neuron(size_t input_size) : weights(Vector(input_size)), bias(0.0), activation(Activation::linear) {}
    Neuron(const Vector& weights, double bias, std::function<double(double)> activation) : weights(weights), bias(bias), activation(activation) {}

    size_t size() const {
        return weights.size();
    }

    double forward(const Vector& inputs) const {
        return activation(weights * inputs + bias);
    }
};