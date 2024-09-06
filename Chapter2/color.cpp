// color.cpp
//
// Author: Zach Schuler
// Lasted Modified: Sept. 2024
//
// Description: Uses the custom made tuple class as a base to hold RGB information and methods.

#include "color.h"

// Default Constructor - Black Pixels
Color::Color() : colorTuple(0, 0, 0, 0) {}


// Parameterized Constructor
Color::Color(float r, float g, float b) : colorTuple(r, g, b, 0) {}


// Copy Constructor
Color::Color(Tuple tp) : colorTuple(tp.x, tp.y, tp.z, 0) {}


// Retrieves the red value
float Color::red() const { return colorTuple.x; }


// Retrieves the green value
float Color::green() const { return colorTuple.y; }


// Retrieves the blue value
float Color::blue() const { return colorTuple.z; }


// Adds all of the values of the colors
Color Color::operator+(const Color & rhs) const
{
    return Color((colorTuple + rhs.colorTuple));

}


// Subtracts all of the values of the colors
Color Color::operator-(const Color & rhs) const
{
    return Color((colorTuple - rhs.colorTuple));
}


// Multiplies all color values by a scalar
Color Color::operator*(const float scalar) const
{
    return Color(colorTuple * scalar);
}


// Multiplies ("blends") two colors
Color Color::operator*(const Color & rhs) const
{
    float r = red() * rhs.red();
    float g = green() * rhs.green();
    float b = blue() * rhs.blue();

    return Color(r, g, b);
}

std::ostream & operator<<(std::ostream& os, const Color &c)
{
    os << '(' << c.red() << ", " << c.green() << ", " << c.blue() << ')';
    return os;
}