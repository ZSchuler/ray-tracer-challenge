#include <iostream>
#include "Chapter1/tuple.h"
#include "Chapter2/color.h"
#include "Chapter2/canvas.h"

using std::cout;
using std::endl;

class Projectile
{
public:
    
    Projectile(Tuple pos, Tuple vel) : position(pos), velocity(vel) {}
    
    Tuple position;
    Tuple velocity;
};

class Enviornment
{
public:
    
    Enviornment(Tuple grav, Tuple wi) : gravity(grav), wind(wi) {}
    
    Tuple gravity;
    Tuple wind;
};

Projectile tick(Enviornment env, Projectile proj)
{
    Tuple position = proj.position + proj.velocity;
    Tuple velocity = proj.velocity + env.gravity + env.wind;
    return Projectile(position, velocity);
}

int main(int argc, char const *argv[])
{
    
    Canvas c = Canvas(1000, 1000);


    // projectile starts one unit above the origin
    // velocity is normalized to 1 unit/tick
    Projectile p = Projectile(Tuple::point(0, 1, 0), (Tuple::vector(1, 1.8, 0)).normalize() * 11.25);


    // gravity -0.1 unit/tick, and wind is -0.01 unit/tick
    Enviornment e = Enviornment(Tuple::vector(0, -0.1, 0), Tuple::vector(-0.01, 0, 0));

    // run tick repeatedly until projectile hits "ground"
    unsigned int ticks = 1;
    while (p.position.y > 0)
    {
        p = tick(e, p);
        cout << ticks << ". Postion: " << p.position << endl;
        ticks++;

        // plot to graph
        int canvasPosX = (int) p.position.x;
        int canvasPosY = c.get_height() - (int) p.position.y;

        if (canvasPosX >= 0 && canvasPosX <= c.get_width() && canvasPosY >= 0 && canvasPosY <= c.get_height())
        {
            c.write_pixel(canvasPosX, canvasPosY, Color(1, 0, 0));
        }
        
    }

    c.canvas_to_ppm();


    return 0;
}
