#ifndef MATRIX_H
#define MATRIX_H

#include <QVector>

typedef u_int8_t TTYPE;

class Matrix
{
public:
    Matrix();
    ~Matrix();
    void readData(const std::string filename);
    Matrix* copy() { return new Matrix(*this); }


    TTYPE data(size_t x, size_t y);
    size_t height() const { return m_dim[1]; }
    size_t width() const { return m_dim[0]; }
    QVector<int> histogram(int bins);
private:
    QVector<TTYPE> m_data;
    size_t m_dim[2];
};


//typedef Matrix<int> Uint8Matrix;

#endif // MATRIX_H
