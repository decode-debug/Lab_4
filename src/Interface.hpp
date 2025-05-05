#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
#include <map>
#include <memory>
#include <vector>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Output_to_html.hpp"

template<typename T>
T get_valid_input(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Nieprawidlowe dane. Sprobuj ponownie.\n";
        }
    }
    return value;
}

inline std::string polski_na_angielski(const std::string& color) {
    static const std::map<std::string, std::string> polskiDoAngielski = {
        {"czerwony", "Red"},
        {"niebieski", "Blue"},
        {"zielony", "Green"},
        {"żółty", "Yellow"},
        {"czarny", "Black"},
        {"biały", "White"}
    };

    if (const auto it = polskiDoAngielski.find(color); it != polskiDoAngielski.end()) {
        return it->second; // Zwróć tłumaczenie
    } else {
        return "Unknown";  // Jeśli klucz nie znaleziony, zwróć "Unknown"
    }
}

inline int choose_your_shape() {
    std::vector<std::string> shapes = {"Kolo", "Prostokat"};
    std::cout << "Wybierz opcje:\n";
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << i + 1 << ". " << shapes[i] << '\n';
    }
    return get_valid_input<int>("Twoj wybor: ");
}

inline shapes::ShapeData get_shape_data(const int shapeType) {
    shapes::ShapeData shape;
    shape.shapeType = shapeType;

    if (shapeType == 1) // Circle
        shape.radius = get_valid_input<int>("Podaj promien: ");
    else if (shapeType == 2) {   // Rectangle
        shape.length = get_valid_input<int>("Podaj dlugosc: ");
        shape.height = get_valid_input<int>("Podaj wysokosc: ");
    }

    const std::vector<std::string> fillings = {"wypelnienie", "ramka"};
    std::cout << "Wybierz opcje wypelnienia:\n";
    for (size_t i = 0; i < fillings.size(); ++i)
        std::cout << i + 1 << ". " << fillings[i] << '\n';
    shape.fillingType = get_valid_input<int>("Twoj wybor: ");

    std::cout << "Podaj kolor: ";
    std::string color;
    std::cin >> color;
    shape.color = polski_na_angielski(color);

    std::cout << "Podaj wspolrzedne polozenia:\n";
    shape.X_axis = get_valid_input<int>("Wspolrzedna x: ");
    shape.Y_axis = get_valid_input<int>("Wspolrzedna y: ");

    return shape;
}

inline int next_decision() {
    std::vector<std::string> decisions = {"Dodaj nowa figure", "To juz wszystko"};
    std::cout << "Wybierz opcje:\n";
    for (size_t i = 0; i < decisions.size(); ++i) {
        std::cout << i + 1 << ". " << decisions[i] << '\n';
    }
    return get_valid_input<int>("Twoj wybor: ");
}


using ShapePtr = std::unique_ptr<shapes::Shape<std::string>>;
using ShapeCollection = std::vector<ShapePtr>;

inline void create_and_add_shape(int shapeType, const shapes::ShapeData& shapeData, ShapeCollection& shapeCollection) {
    if (shapeType == 2) { // Rectangle
        auto rectangle_ptr = std::make_unique<shapes::Rectangle<std::string>>(shapeData);
        shapeCollection.emplace_back(std::move(rectangle_ptr));
    }    if (shapeType == 1) { //Circle
        auto rectangle_ptr = std::make_unique<shapes::Circle<std::string>>(shapeData);
        shapeCollection.emplace_back(std::move(rectangle_ptr));
    }
}

[[noreturn]] inline void Interface() {
    ShapeCollection shapeCollection;
    while (true) {
        const int selected_shape_type = choose_your_shape();
        shapes::ShapeData shape_data = get_shape_data(selected_shape_type);

        create_and_add_shape(selected_shape_type, shape_data, shapeCollection);

        if (const int user_decision = next_decision(); user_decision != 1) {
            break;
        }
    }
    output::output_to_html(shapeCollection);
}