// matrix.cpp
//
// Author: Zach Schuler
// Lasted Modified: Sept. 2024
//
// Description: Uses a 2D array to store information about a matrix & its methods
//              for the purpose of computer graphics. :)

#include "matrix.h"
#include <iostream>
#include <cmath>

bool Matrix::fequal(float a, float b) const
{
    return fabs(a - b) < MATRIX_EPSILON;
}

Matrix::Matrix()
{

}

Matrix::Matrix(int dim)
{
    size = dim;

    // allocate the memory
    matrix = new float*[dim];
    for (int i = 0; i < dim; i++)
    {
        matrix[i] = new float[dim];
    }

    // default the matrix to zero
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    // deallocate the matrix
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

void Matrix::printMatrix() const
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

bool Matrix::operator==(const Matrix & rhs) const
{   
    if (size != rhs.size) return false;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (!fequal(matrix[i][j], matrix[i][j])) return false;
        }
    }

    return true;
}