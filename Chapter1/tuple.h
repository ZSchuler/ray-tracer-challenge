// tuple.h
//
// Author: Zach Schuler
// Lasted Modified: Sept. 2024
//
// Description: Custom tuple 4-tuple class which includes various methods
//              and overloaded operators for the purpose of computer graphics.

#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>

class Tuple
{

private:

    const float TUPLE_EPSILON = 0.00001;

    // Compares two floats using the TUPLE_EPSILON
    bool equal(float a, float b);

public:

    float x, y, z, w;

    // Default Constructor
    Tuple();

    // Paramaterized Constructor
    Tuple(float a, float b, float c, float d);


    // Function to create a point
    static Tuple point(float a, float b, float c);


    // Function to create a vector
    static Tuple vector(float a, float b, float c);


    // Returns true if the Tuple is a point
    bool isPoint() const;


    // Returns true if the Tuple is a vector
    bool isVector() const;


    // Overloaded equality operator
    bool operator==(Tuple & rhs);


    // Overloaded addition operator
    Tuple operator+(const Tuple & rhs) const;


    // Overloaded substraction operator
    Tuple operator-(const Tuple & rhs) const;


    // Overload unary minus operator (negation)
    Tuple operator-() const;


    // Overloaded multiplication operator for scalars
    Tuple operator*(const float scalar) const;


    // Overloaded division operator for scalars
    Tuple operator/(const float scalar) const;


    // Overloaded assignment operator
    Tuple & operator=(const Tuple & rhs);


    // Computes and returns the magnitude of the vector
    float magnitude() const;


    // Returns a normalized version of the vector
    Tuple normalize() const;


    // Computes the dot product given another vector
    float dot(const Tuple & b) const;


    // Computes the cross product given another vector
    Tuple cross(const Tuple & b) const;


    // Friend function to overload the output
    friend std::ostream & operator<<(std::ostream& os, const Tuple &tp);

};

#endif // TUPLE_H