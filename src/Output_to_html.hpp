//
// Created by mikol on 03.05.2025.
//
#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "Rectangle.hpp"
#include "Circle.hpp"
#ifndef OUTPUT_TO_HTML_HPP
#define OUTPUT_TO_HTML_HPP
namespace output{
    using ShapePtr = std::unique_ptr<shapes::Shape<std::string>>;
    using ShapeCollection = std::vector<ShapePtr>;

void writeRectangleToSvg(std::ofstream& svg, const auto rectangle) {

    auto data = rectangle->return_data();
    constexpr auto RECTANGLE_len = data[1];
    constexpr auto RECTANGLE_hei = data[2];
    constexpr auto RECTANGLE_X = data[3];
    constexpr auto RECTANGLE_Y = data[4];
    constexpr auto RECTANGLE_COLOR = data[5];
    constexpr auto RECTANGLE_Filling = data[6];
    std::string filling;
    if (RECTANGLE_Filling == 1)
        filling = "fill";
    else if (RECTANGLE_Filling == 2)
        filling = "stroke";
    svg << "  <rect x=\"" << RECTANGLE_X << "\" y=\"" << RECTANGLE_Y << "\" width=\""
    << RECTANGLE_len << "\" height=\"" << RECTANGLE_hei << "\"" << filling << "=\"" << RECTANGLE_COLOR << "\" />\n";
}
    void writeCircleToSvg(std::ofstream& svg, const auto circle) {

    auto data = circle->return_data();
    constexpr auto radius = data[1];
    constexpr auto Circle_X = data[2];
    constexpr auto Circle_Y = data[3];
    constexpr auto Circle_COLOR = data[4];
    constexpr auto Circle_Filling = data[5];
    std::string filling;
    if (Circle_Filling == 1)
        filling = "fill";
    else if (Circle_Filling == 2)
        filling = "stroke";
    svg << "  <circle cx=\"" << Circle_X << "\" cy=\"" << Circle_Y << "\" r=\"" <<
        radius << "\" " << filling << "=\"" << Circle_COLOR << "\" />\n";
}

[[noreturn]] inline void output_to_html(const ShapeCollection shape_collection){
    std::ofstream svg("image.html");
    if (!svg)
        std::cerr << "Couldn't open the file!" << std::endl;

    svg << "<!DOCTYPE html>\n";
    svg << "<html lang=\"en\">\n";
    svg << "<head>\n";
    svg << "<meta charset=\"UTF-8\">\n";
    svg << "<title>SVG Render</title>\n";
    svg << "</head>\n";
    svg << "<body>\n";
    svg << "<svg width=\"300\" height=\"200\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n";

    auto handleShape(const std::unique_ptr<shapes::Shape<std::string>> shape) -> void; {
        if (!shape) {
            std::cerr << "Null shape pointer provided!" << std::endl;
            return;
        }

        if (auto rectangle = dynamic_cast<shapes::Rectangle<std::string>*>(shape.get())) {
            writeRectangleToSvg(svg, rectangle);
        } else if (auto circle = dynamic_cast<shapes::Circle<std::string>*>(shape.get())) {
            writeCircleToSvg(svg, circle);
        } else {
            std::cerr << "Unknown shape type!" << std::endl;
        }
    }

    for (const auto& shape : shape_collection) {
        handleShape(shape);
    }

    // Tworzymy elementy SVG w pliku
    svg << "  <rect width=\"300\" height=\"100\" fill=\"red\" />\n";
    svg << "  <rect x=\"10\" y=\"10\" width=\"280\" height=\"180\" fill=\"none\" stroke=\"blue\" />\n";
    svg << "  <circle cx=\"150\" cy=\"100\" r=\"80\" fill=\"green\" />\n";
    svg << "  <text x=\"150\" y=\"125\" font-size=\"60\" text-anchor=\"middle\" fill=\"white\">SVG</text>\n";
    svg << "  <text x=\"280\" y=\"180\" font-size=\"20\" text-anchor=\"end\" fill=\"blue\">24.Z</text>\n";

    // Zamykamy elementy HTML i SVG
    svg << "</svg>\n";
    svg << "</body>\n";
    svg << "</html>\n";

    // Zamykamy plik
    svg.close();
}

}
#endif //OUTPUT_TO_HTML_HPP
