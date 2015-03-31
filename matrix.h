#ifndef MATRIX_H
#define MATRIX_H

#include <QVector>

typedef u_int8_t TTPYE;

class Matrix
{
public:
    Matrix();
    ~Matrix();
    void readData(const std::string filename);

    TTPYE data(size_t x, size_t y);
    size_t height() const { return m_dim[1]; }
    size_t width() const { return m_dim[0]; }
private:
    QVector<TTPYE> m_data;
    size_t m_dim[2];
};


//typedef Matrix<int> Uint8Matrix;

#endif // MATRIX_H
