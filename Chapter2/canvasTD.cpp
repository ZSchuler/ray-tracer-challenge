#include <iostream>
#include "canvas.h"

int main(int argc, char const *argv[])
{
    
    Canvas c = Canvas(10, 2);
    
    Color c1 = Color(1, 0.8, 0.6);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            c.write_pixel(j, i, c1);
        }
    }

    c.canvas_to_ppm();

    return 0;
}
