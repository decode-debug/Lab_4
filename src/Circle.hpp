#pragma once

#include "Shape.hpp"
namespace shapes{
	// Klasa koła dziedzicząca po Shape
	template <typename T>
	class Circle final : public Shape<T> {
	private:
		T radius;
		T X_axis;
		T Y_axis;
		T color;
        T fillingType;

	public:
		explicit Circle(const ShapeData& data)
			: radius(static_cast<T>(data.radius)),
			  X_axis(static_cast<T>(data.X_axis)),
			  Y_axis(static_cast<T>(data.Y_axis)),
			  color(static_cast<T>(data.color)),
			  fillingType(static_cast<T>(data.fillingType)) {}

		T area() const override;

		T return_data() const override;
	};
}
#include "Circle_impl.hpp"
