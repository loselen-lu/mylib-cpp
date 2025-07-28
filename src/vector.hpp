#pragma once

#include <vector>
#include <initializer_list>
#include <cassert>
#include <iostream>

class Vector {
private:
    std::vector<double> data;
public:
    Vector(const std::initializer_list<double>& data) : data(data) {}
    Vector(const std::vector<double>& data) : data(data) {}

    size_t size() const {
        return data.size();
    }

    Vector operator+(const Vector& other) const {
        assert(data.size() == other.data.size());
        std::vector<double> res(data.size());
        for (size_t i = 0; i < data.size(); i++) {
            res[i] = data[i] + other.data[i];
        }
        return Vector(res);
    }

    double operator*(const Vector& other) const {
        assert(data.size() == other.data.size());
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