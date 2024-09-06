// matrix.h
//
// Author: Zach Schuler
// Lasted Modified: Sept. 2024
//
// Description: Uses a 2D array to store information about a matrix & its methods
//              for the purpose of computer graphics.

class Matrix
{
private:

    int size;


    const float MATRIX_EPSILON = 0.00001;
    bool fequal(float a, float b) const;

public:

    float **matrix = nullptr;

    Matrix();

    Matrix(int dim);

    ~Matrix();

    void printMatrix() const;

    bool operator==(const Matrix & rhs) const;

};