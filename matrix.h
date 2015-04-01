#ifndef MATRIX_H
#define MATRIX_H

#include <QVector>

// Generic Matrix
class GMatrix
{
public:
    GMatrix() {}
    virtual ~GMatrix() {}
    virtual void readData(const std::string filename)=0;
    virtual GMatrix* copy()=0;
    virtual size_t height() const=0;
    virtual size_t width() const=0;
    virtual QVector<int> histogram(int bins)=0;
};


template <class TTYPE>
class Matrix : public GMatrix
{
public:
    Matrix(){}
    virtual ~Matrix(){}
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

typedef Matrix<u_int8_t> U8Matrix;
typedef Matrix<float> FMatrix;
#include "matrix.cpp"

#endif // MATRIX_H
