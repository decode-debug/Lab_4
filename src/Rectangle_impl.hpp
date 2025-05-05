#pragma once
#include <iostream>
#include "Shape.hpp"
#include "Rectangle.hpp"


template <typename T> T shapes::Rectangle<T>::area() const {
    return length * height;
}
template <typename T> T shapes::Rectangle<T>::return_data() const{
    return {length,height, X_axis, Y_axis, color, fillingType};
}
