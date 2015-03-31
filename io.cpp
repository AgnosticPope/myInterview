// Module: io.cpp
// Author: Nicholas Apostoloff, Blue River Technology Inc.
// Email: nick.a@bluerivert.com
// Created: 12 Dec 14

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>
#include <vector>
#include <assert.h>
#include <stdlib.h>

/** Read a matrix from a csv file where the first two elements are the
    height and width of the matrix respectively, while the rest of the
    data is a uint8 matrix in row major order of size height x width.

    @param[in] filename The name of the file on disk.

    @param[out] matrix A vector of height*width length containing the
    matrix data in row major order.

    @param[out] height The number of rows in the matrix.

    @param[out] width The number of columns in the matrix.

    NOTE: There is no error checking in this code.  It will work with
    the file I provided but does not handle errors in the file or
    missing files.  Feel free to add this error checking if you'd like
    to.
*/
void readUint8Matrix(const std::string filename, 
                    std::vector<uint8_t>& matrix, 
                    unsigned int& height,
                    unsigned int& width)
{
    // Open the file
    std::ifstream file(filename.c_str());

    matrix.clear();
    std::string value;

    // Get the height of the matrix
    std::getline(file, value, ',');
    assert(file.good());
    height = atoi(value.c_str());

    // Get the width of the matrix
    std::getline(file, value, ',');
    assert(file.good());
    width = atoi(value.c_str());

    // Collect matrix data
    matrix.reserve(width*height);
    while(file.good())
    {
        std::getline(file, value, ','); // Read a string until the next comma
        matrix.push_back(atoi(value.c_str())); // Convert the string to an int
    }
    assert(matrix.size() == width*height);
}
