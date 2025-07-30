#pragma once

#include <vector>
#include <initializer_list>
#include <iostream>

class Vector {
private:
    std::vector<double> data;
public:
    Vector(size_t size) : data(size, 0.0) {}
    Vector(const std::initializer_list<double>& data) : data(data) {}
    Vector(const std::vector<double>& data) : data(data) {}

    size_t size() const {
        return data.size();
    }

    const double& operator[](size_t index) const {
        return data[index];
    }
    double& operator[](size_t index) {
        return data[index];
    }

    Vector operator+(const Vector& other) const {
        std::vector<double> res(data.size());
        for (size_t i = 0; i < data.size(); i++) {
            res[i] = data[i] + other.data[i];
        }
        return Vector(res);
    }

    double operator*(const Vector& other) const {
        double res = 0;
        for (size_t i = 0; i < data.size(); i++) {
            res += data[i] * other.data[i];
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& vec) {
        out << '(';
        for (size_t i = 0; i < vec.data.size(); i++) {
            out << vec.data[i];
            if (i < vec.data.size() - 1) {
                out << ", ";
            }
        }
        out << ')';
        return out;
    }
};