# mylib-cpp: A Lightweight C++ Neural Network Core

[](https://opensource.org/licenses/MIT)
[](https://en.wikipedia.org/wiki/C%2B%2B11)

## 🌟 Overview

**mylib-cpp** is a concise and easy-to-understand C++ library providing the fundamental building blocks for neural networks. It's designed for educational purposes, rapid prototyping of simple network structures, or as a starting point for more complex implementations. With a focus on clarity and directness, mylib-cpp offers core components like `Vector` for numerical operations, `Activation` functions, `Neuron`s, and `Layer`s.

**Key Features:**

  * **Vector Operations:** Basic vector arithmetic (`+`, `*` for dot product) and element access.
  * **Activation Functions:** Common activation functions (`linear`, `relu`).
  * **Neuron Implementation:** A single neuron with weights, bias, and a pluggable activation function.
  * **Layer Abstraction:** A collection of neurons forming a dense layer.
  * **Pure C++:** No external dependencies beyond the standard library.

## 🚀 Getting Started

mylib-cpp is a header-only library, making it incredibly easy to integrate into your C++ projects.

### Prerequisites

  * A C++11 (or newer) compatible compiler (e.g., GCC, Clang, MSVC).

### Installation

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/loselen-lu/mylib-cpp.git
    cd mylib-cpp
    ```
2.  **Include in your project:** Simply copy the `src/` directory and `mylib.hpp` into your project's include path. Then, include `mylib.hpp` in your source files:
    ```cpp
    #include "mylib.hpp"

    // Your code
    int main() {
        // ...
    }
    ```

## 🛠️ Usage Examples

Let's see how to use mylib-cpp to create a basic neural network layer.

### Example 1: Basic Vector Operations

```cpp
#include "mylib.hpp"
#include <iostream>

int main() {
    Vector v1 = {1.0, 2.0, 3.0};
    Vector v2(3); // Initializes with 0s: (0.0, 0.0, 0.0)
    v2[0] = 4.0;
    v2[1] = 5.0;
    v2[2] = 6.0;

    std::cout << "v1: " << v1 << std::endl; // Output: (1, 2, 3)
    std::cout << "v2: " << v2 << std::endl; // Output: (4, 5, 6)

    // Vector addition
    Vector sum = v1 + v2;
    std::cout << "v1 + v2: " << sum << std::endl; // Output: (5, 7, 9)

    // Dot product
    double dot_product = v1 * v2;
    std::cout << "v1 * v2 (dot product): " << dot_product << std::endl; // Output: 32 (1*4 + 2*5 + 3*6 = 4+10+18)

    // Modifying elements
    v1[1] = 10.0;
    std::cout << "v1 (modified): " << v1 << std::endl; // Output: (1, 10, 3)

    return 0;
}
```

### Example 2: Creating a Neuron

```cpp
#include "mylib.hpp"
#include <iostream>

int main() {
    // Create a neuron with 3 inputs, default bias 0.0, and linear activation
    Neuron neuron1(3); 

    // Set custom weights (accessing underlying Vector directly via operator[])
    neuron1.weights[0] = 0.5;
    neuron1.weights[1] = -0.2;
    neuron1.weights[2] = 0.8;
    // neuron1.bias remains 0.0

    // Or, create a neuron with custom weights, bias, and ReLU activation
    Vector custom_weights = {0.1, 0.9};
    Neuron neuron2(custom_weights, 0.1, Activation::relu);

    Vector inputs1 = {1.0, 2.0, 3.0};
    double output1 = neuron1.forward(inputs1);
    std::cout << "Neuron 1 output (linear): " << output1 << std::endl; 
    // Calculation: (0.5*1.0 + -0.2*2.0 + 0.8*3.0) + 0.0 = (0.5 - 0.4 + 2.4) = 2.5

    Vector inputs2 = {-1.0, 0.5};
    double output2 = neuron2.forward(inputs2);
    std::cout << "Neuron 2 output (relu): " << output2 << std::endl; 
    // Calculation: (0.1*-1.0 + 0.9*0.5) + 0.1 = (-0.1 + 0.45) + 0.1 = 0.35 + 0.1 = 0.45
    // ReLU(0.45) = 0.45

    return 0;
}
```

### Example 3: Building a Simple Layer

```cpp
#include "mylib.hpp"
#include <iostream>

int main() {
    // Create a layer with 3 inputs and 2 outputs
    Layer layer1(3, 2);

    // Initial weights are all zeros. Let's imagine setting them for demonstration:
    // (In a real scenario, you'd typically initialize weights randomly or load them)

    // Accessing neurons within the layer (for advanced customization or inspection)
    // For neuron 0 (output 0):
    // layer1.neurons[0].weights = {0.1, 0.2, 0.3}; // This line won't compile without a public setter
    // To modify neurons, you'd need public accessors or a different initialization strategy.
    // For this example, we'll rely on the default (zero-initialized) neurons,
    // or assume they are configured internally.

    Vector layer_inputs = {1.0, 2.0, 3.0};
    Vector layer_outputs = layer1.forward(layer_inputs);

    std::cout << "Layer output: " << layer_outputs << std::endl; 
    // Since default neuron weights/bias are 0, and activation is linear:
    // Neuron 0 output: (0*1 + 0*2 + 0*3) + 0 = 0 -> linear(0) = 0
    // Neuron 1 output: (0*1 + 0*2 + 0*3) + 0 = 0 -> linear(0) = 0
    // Output: (0, 0)
    // You would typically train or explicitly set weights to get meaningful output.

    return 0;
}
```

## 📚 API Reference

### `Vector` Class (./src/vector.hpp)

A basic dynamic array for double-precision floating-point numbers.

  * **Constructors:**
      * `Vector(size_t size)`: Creates a vector of `size` elements, initialized to `0.0`.
      * `Vector(const std::initializer_list<double>& data)`: Creates a vector from an initializer list.
      * `Vector(const std::vector<double>& data)`: Creates a vector from an existing `std::vector<double>`.
  * **Methods:**
      * `size_t size() const`: Returns the number of elements in the vector.
      * `const double& operator[](size_t index) const`: Provides const-access to elements.
      * `double& operator[](size_t index)`: Provides mutable access to elements.
  * **Operators:**
      * `Vector operator+(const Vector& other) const`: Element-wise vector addition. **Assumes equal sizes.**
      * `double operator*(const Vector& other) const`: Dot product. **Assumes equal sizes.**
      * `friend std::ostream& operator<<(std::ostream& out, const Vector& vec)`: Stream insertion for easy printing.

### `Activation` Class (./src/activation.hpp)

A utility class providing static activation functions.

  * **Static Methods:**
      * `static double linear(double input)`: Returns the input value (identity function).
      * `static double relu(double input)`: Returns `input` if `input > 0`, else `0`.

### `Neuron` Class (./src/neuron.hpp)

Represents a single neuron with weights, bias, and an activation function.

  * **Constructors:**
      * `Neuron(size_t input_size)`: Creates a neuron with `input_size` weights (all `0.0`), `bias` `0.0`, and `linear` activation.
      * `Neuron(const Vector& weights, double bias, std::function<double(double)> activation)`: Creates a neuron with specified weights, bias, and activation function.
  * **Methods:**
      * `size_t size() const`: Returns the number of input weights.
      * `double forward(const Vector& inputs) const`: Calculates the neuron's output for given inputs. **Assumes `inputs.size()` matches neuron's `weights.size()`.**

### `Layer` Class (./src/layer.hpp)

Represents a dense (fully connected) layer of neurons.

  * **Constructors:**
      * `Layer(size_t input_size, size_t output_size)`: Creates a layer with `output_size` neurons, each expecting `input_size` inputs. All neurons are initialized with default (zero) weights and linear activation.
  * **Methods:**
      * `size_t input_size() const`: Returns the expected input size for the layer.
      * `size_t output_size() const`: Returns the number of neurons (and thus outputs) in the layer.
      * `Vector forward(const Vector& inputs) const`: Computes the outputs of all neurons in the layer for given inputs. **Assumes `inputs.size()` matches `input_size()` of the layer.**

## ⚠️ Important Considerations

  * **No Runtime Error Checks:** This library prioritizes simplicity. Operations like `Vector` addition/dot product, `Neuron::forward`, and `Layer::forward` **do not perform runtime checks** for matching input dimensions. Providing mismatched sizes will lead to undefined behavior (e.g., crashes or incorrect results). It is the user's responsibility to ensure correct dimensions.
  * **No Training Mechanisms:** This library provides only the forward pass components. It does not include any mechanisms for training (e.g., backpropagation, optimizers, loss functions). It's designed as a foundational piece upon which such features could be built.
  * **Basic Implementations:** The current implementations are basic. For high-performance or production-grade applications, consider libraries optimized for linear algebra (e.g., Eigen, BLAS/LAPACK) and neural network frameworks (e.g., TensorFlow Lite, ONNX Runtime).

## 🤝 Contributing

Contributions are welcome\! If you find a bug, have a suggestion for improvement, or want to add a feature:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/your-feature-name`).
3.  Make your changes.
4.  Commit your changes (`git commit -m 'feat: Add new feature'`).
5.  Push to the branch (`git push origin feature/your-feature-name`).
6.  Open a Pull Request.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](https://www.google.com/search?q=LICENSE) file for details.

-----

*Made with ❤️ by [loselen-lu](https://www.google.com/search?q=https://github.com/loselen-lu)*