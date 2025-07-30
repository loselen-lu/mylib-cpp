#pragma once

#include <vector>
#include "neuron.hpp"

class Layer {
private:
    std::vector<Neuron> neurons;
public:
    Layer(size_t input_size, size_t output_size) {
        neurons.assign(output_size, Neuron(input_size));
    }

    size_t input_size() const {
        return neurons[0].size();
    }

    size_t output_size() const {
        return neurons.size();
    }

    Vector forward(const Vector& inputs) const {
        Vector res(output_size());
        for (size_t i = 0; i < output_size(); i++) {
            res[i] = neurons[i].forward(inputs);
        }
        return res;
    }
};