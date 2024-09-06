// canvas.cpp
//
// Author: Zach Schuler
// Lasted Modified: Sept. 2024
//
// Description: Uses a 2D array to store pixel information. Includes a method
//              to convert this information into a .ppm file.

#include "canvas.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>

void Canvas::writeColorComponent(std::ofstream& theFile, std::string& data, int& lineLength) const
{
    int dataLen = data.length();
    if (lineLength + dataLen > 70)
    {
        theFile << '\n';
        lineLength = 0;
    }
    theFile << data;
    lineLength += dataLen;
}

Canvas::Canvas(unsigned int w, unsigned int h)
{
    width = w;
    height = h;
    
    canvasArr = new Color*[height];
    for (int i = 0; i < h; i++)
    {
        canvasArr[i] = new Color[width];
    }
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; i++)
    {
        delete[] canvasArr[i];
    }
    delete[] canvasArr;
}

Color Canvas::pixel_at(unsigned int x, unsigned int y) const
{
    return canvasArr[y][x];
}

void Canvas::write_pixel(unsigned int x, unsigned int y, Color color)
{
    canvasArr[y][x] = color;
}

void Canvas::canvas_to_ppm() const
{
    
    std::ofstream theFile;
    theFile.open("example.ppm");

    theFile << "P3\n";
    theFile << width << " " << height << '\n';
    theFile << "255\n";

    for (int i = 0; i < height; i++)
    {
        
        int lineLength = 0;
        
        for (int j = 0; j < width; j++)
        {
            
            int r = std::min(255, std::max(0, static_cast<int>(ceil(canvasArr[i][j].red() * 255))));
            int g = std::min(255, std::max(0, static_cast<int>(ceil(canvasArr[i][j].green() * 255))));
            int b = std::min(255, std::max(0, static_cast<int>(ceil(canvasArr[i][j].blue() * 255))));
            
            std::string redData = std::to_string(r) + " ";
            std::string greenData = std::to_string(g) + " ";
            std::string blueData = std::to_string(b) + " ";

            writeColorComponent(theFile, redData, lineLength);
            writeColorComponent(theFile, greenData, lineLength);
            writeColorComponent(theFile, blueData, lineLength);


        }
        theFile << '\n';
    }

    theFile << '\n';

    theFile.close();
}

unsigned int Canvas::get_height() const { return height; }

unsigned int Canvas::get_width() const { return width; }