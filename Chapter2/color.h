// color.h
//
// Author: Zach Schuler
// Lasted Modified: Sept. 2024
//
// Description: Uses the custom made tuple class as a base to hold RGB information and methods.

#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "../Chapter1/tuple.h"

class Color
{
private:

    Tuple colorTuple;

public:

    // Default Constructor - Black Pixels
    Color();    


    // Parameterized Constructor
    Color(float r, float g, float b);


    // Copy Constructor
    Color(Tuple tp);


    // Retrieves the red value
    float red() const;


    // Retrieves the green value
    float green() const;


    // Retrieves the blue value
    float blue() const;


    // Adds all of the values of the colors
    Color operator+(const Color & rhs) const;


    // Subtracts all of the values of the colors
    Color operator-(const Color & rhs) const;


    // Multiplies all color values by a scalar
    Color operator*(const float scalar) const;


    // Multiplies ("blends") two colors
    Color operator*(const Color & rhs) const;

    friend std::ostream & operator<<(std::ostream& os, const Color &c);

};







#endif // COLOR_H