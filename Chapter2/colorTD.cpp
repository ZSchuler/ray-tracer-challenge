#include <iostream>
#include "color.h"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    
    Color c1 = Color(1, 0.2, 0.4);
    Color c2 = Color(0.9, 1, 0.1);


    cout << c1 * c2 << endl;

    return 0;
}
