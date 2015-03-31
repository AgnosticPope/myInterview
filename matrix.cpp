#include "matrix.h"
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>
#include <vector>
#include <assert.h>
#include <stdlib.h>
#include <QDebug>
#include <math.h>
//template <class T>

template <class TTYPE>
TTYPE Matrix<TTYPE>::data(size_t x, size_t y)
{
    return m_data.at(x + width() * y);
}

template <class TTYPE>
QVector<int> Matrix<TTYPE>::histogram(int bins)
{
    QVector<int> histo(bins);
    int binsize(pow(sizeof(TTYPE)*16,2)/bins);
    for (TTYPE i : m_data)
    {
        histo[i/binsize]++;
    }
    std::cout<<"\nBinsize is " << binsize << std::endl;
    return histo;
}

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
template <class TTYPE>
void
Matrix<TTYPE>::readData(const std::string filename)
{
    // Open the file
    std::ifstream file(filename.c_str());

    m_data.clear();
    std::string value;

    // Get the height of the matrix
    std::getline(file, value, ',');
    assert(file.good());
    m_dim[1] = atoi(value.c_str());

    // Get the width of the matrix
    std::getline(file, value, ',');
    assert(file.good());
    m_dim[0] = atoi(value.c_str());

    // Collect matrix data
    m_data.reserve(width()*height());
    while(file.good())
    {
        std::getline(file, value, ','); // Read a string until the next comma
        m_data.append(atoi(value.c_str())); // Convert the string to an int
    }
    assert(m_data.size() == width()*height());
}

