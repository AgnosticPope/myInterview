// Application: main
// Author: Nicholas Apostoloff, Blue River Technology Inc.
// Email: nick.a@bluerivert.com
// Created: 12 Dec 14
//
//-----------------------------------------------------------------------------

#include <vector>
#include <iostream>
#include <stdint.h>
#include "matrix.h"

#include "io.hpp"

using std::cout;

/** This is an example program that reads a matrix represented in a
    CSV file into a std::vector and prints the matrix values to the
    terminal.
*/
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Error!  Please supply a filename on the command line." << std::endl;
        return 1;
    }
    Matrix m;
    m.readData(argv[1]);
    std::cout << "Read a matrix of size [" << m.height() << "," << m.width() << "]:" << std::endl;
    for (size_t y = 0; y < m.height(); y++)
    {
        cout << "\n";
        for (size_t x = 0; x < m.width(); x++)
        {
            cout << (int)m.data(x,y) << " ";
        }
    }

}
