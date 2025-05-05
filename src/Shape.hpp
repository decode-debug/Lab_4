#pragma once

namespace shapes
{
	template <typename T>
	class Shape {
	public:
		Shape() = default;
		virtual ~Shape() = default;
		Shape(const Shape&) = default;
		Shape& operator=(const Shape&) = default;
		Shape(Shape&&) noexcept = default;
		Shape& operator=(Shape&&) noexcept = default;

		virtual T area() const = 0;
		virtual T return_data() const = 0;
	};


	struct ShapeData {
		int shapeType{};
		int X_axis{};
		int Y_axis{};
		std::string color;
		int fillingType{};
		int radius {0};
		int height {0};
		int length {0};

		ShapeData() = default;

		~ShapeData() = default;

		ShapeData(const ShapeData& other) noexcept = default;

		//operator=
		ShapeData& operator=(const ShapeData& other) noexcept {
			if (this != &other) {
				shapeType = other.shapeType;
				X_axis = other.X_axis;
				Y_axis = other.Y_axis;
				color = other.color;
				fillingType = other.fillingType;
				radius = other.radius;
				height = other.height;
				length = other.length;
			}
			return *this;
		}

		// moving
		ShapeData(ShapeData&& other) noexcept
			: shapeType(std::move(other.shapeType)),
			  X_axis(std::move(other.X_axis)),
			  Y_axis(std::move(other.Y_axis)),
			  color(std::move(other.color)),
			  fillingType(std::move(other.fillingType)),
			  radius(std::move(other.radius)),
			  height(std::move(other.height)),
			  length(std::move(other.length)) {}

		// moving with operator=
		ShapeData& operator=(ShapeData&& other) noexcept {
			if (this != &other) {
				shapeType = std::move(other.shapeType);
				X_axis = std::move(other.X_axis);
				Y_axis = std::move(other.Y_axis);
				color = std::move(other.color);
				fillingType = std::move(other.fillingType);
				radius = std::move(other.radius);
				height = std::move(other.height);
				length = std::move(other.length);
			}
			return *this;
		}
};
}// End of namespace shapes