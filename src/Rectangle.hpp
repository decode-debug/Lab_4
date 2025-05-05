#pragma once

#include "Shape.hpp"

namespace shapes
{
    template <typename T>
    class Rectangle final : public Shape<T> {
    private:
    T length;
    T height;
    T X_axis;
    T Y_axis;
    T color;
    T fillingType;
    public:
    explicit Rectangle(const ShapeData& data)
        : length(static_cast<T>(data.length)),
          height(static_cast<T>(data.height)),
          X_axis(static_cast<T>(data.X_axis)),
          Y_axis(static_cast<T>(data.Y_axis)),
          fillingType(static_cast<T>(data.fillingType)),
          color(data.color) {}

        T area() const override;
        T return_data() const override;
    };

}
#include "Rectangle_impl.hpp"