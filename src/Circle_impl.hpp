#include <math.h>
#include <numbers>
#include "Circle.hpp"

template <typename T> T shapes::Circle<T>::area() const {
    return std::numbers::pi * radius * radius;
}

template <typename T> T shapes::Circle<T>::return_data() const{
    return {radius, X_axis, Y_axis, color, fillingType};
}
