#include <iostream>
#include "matrix.h"

int main(int argc, char const *argv[])
{
    
    Matrix m(4);
    
    //m.matrix[0][0] = 1;

    //m.printMatrix();

    Matrix m2(4);

    std::cout << (m == m2) << std::endl;


    return 0;
}
