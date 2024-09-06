// canvas.h
//
// Author: Zach Schuler
// Lasted Modified: Sept. 2024
//
// Description: Uses a 2D array to store pixel information. Includes a method
//              to convert this information into a .ppm file.

#include "color.h"

class Canvas
{
private:

    unsigned int width;
    unsigned int height;

    Color **canvasArr;

    void writeColorComponent(std::ofstream& theFile, std::string& data, int& lineLength) const;

public:

    Canvas(unsigned int w, unsigned int h);

    ~Canvas();

    void write_pixel(unsigned int x, unsigned int y, Color color);

    Color pixel_at(unsigned int x, unsigned int y) const;

    void canvas_to_ppm() const;

    unsigned int get_height() const;

    unsigned int get_width() const;

};