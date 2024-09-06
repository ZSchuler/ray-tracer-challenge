#include "tuple.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    
    Tuple a = Tuple::vector(1, 2, 3);
    Tuple b = Tuple::vector(2, 3, 4);

    cout << b.cross(a) << endl;

    return 0;
}
