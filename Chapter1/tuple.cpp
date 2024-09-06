// tuple.cpp
//
// Author: Zach Schuler
// Lasted Modified: Sept. 2024
//
// Description: Custom tuple 4-tuple class which includes various methods
//              and overloaded operators for the purpose of computer graphics.

#include <cmath>
#include <iostream>
#include "tuple.h"


// PRIVATE METHODS


// Compares two floats using the TUPLE_EPSILON
bool Tuple::equal(float a, float b)
{
    return fabs(a - b) < TUPLE_EPSILON;
}



// PUBLIC METHODS

// Default Constructor
Tuple::Tuple()
{
   x = 0.0f;
   y = 0.0f; 
   z = 0.0f; 
   w = 0.0f; 
}

// Paramaterized Constructor
Tuple::Tuple(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}


// Function to create a point
Tuple Tuple::point(float a, float b, float c)
{
    return Tuple(a, b, c, 1.0f);
}


// Function to create a vector
Tuple Tuple::vector(float a, float b, float c)
{
    return Tuple(a, b, c, 0.0f);
}


// Returns true if the Tuple is a point
bool Tuple::isPoint() const { return abs(w - 1) < TUPLE_EPSILON; }


// Returns true if the Tuple is a vector
bool Tuple::isVector() const { return abs(w - 0) < TUPLE_EPSILON; }


// Overloaded equality operator
bool Tuple::operator==(Tuple & rhs)
{
    return equal(this->x, rhs.x) && equal(this->y, rhs.y) &&
            equal(this->z, rhs.z) && equal(this->w, rhs.w);
}


// Overloaded addition operator
Tuple Tuple::operator+(const Tuple& rhs) const
{
    return Tuple(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}


// Overloaded substraction operator
Tuple Tuple::operator-(const Tuple & rhs) const
{
    return Tuple(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}


// Overload unary minus operator (negation)
Tuple Tuple::operator-() const
{
    return Tuple(-x, -y, -z, -w);
}


// Overloaded multiplication operator for scalars
Tuple Tuple::operator*(const float scalar) const
{
    return Tuple(x * scalar, y * scalar, z * scalar, w * scalar);
}


// Overloaded division operator for scalars
Tuple Tuple::operator/(const float scalar) const
{
    return Tuple(x / scalar, y / scalar, z / scalar, w / scalar);
}


// Overloaded assignment operator
Tuple & Tuple::operator=(const Tuple & rhs)
{
    if (this == &rhs) return *this;

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;

    return *this;
}


// Computes and returns the magnitude of the vector
float Tuple::magnitude() const
{
    return sqrt(x*x + y*y + z*z + w*w);
}


// Returns a normalized version of the vector
Tuple Tuple::normalize() const
{
    float mag = magnitude();
    return Tuple(x / mag, y / mag, z / mag, w / mag);
}


// Computes the dot product given another vector
float Tuple::dot(const Tuple & b) const
{
    return (x * b.x) + (y * b.y) + (z * b.z) + (w * b.w);
}


// Computes the cross product given another vector
Tuple Tuple::cross(const Tuple & b) const
{
    return vector(y * b.z - z * b.y,
                  z * b.x - x * b.z,
                  x * b.y - y * b.x);
}


// Friend function to overload the output
std::ostream & operator<<(std::ostream& os, const Tuple &tp)
{
    os << '(' << tp.x << ", " << tp.y << ", " << tp.z << ", " << tp.w << ')';
    return os;
}