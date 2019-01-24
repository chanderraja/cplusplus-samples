//
// Created by Chander Raja on 2019-01-24.
//
///


#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cstring>

namespace mycorp {

///
/// \tparam T matrix data type (int, float, double etc)
/// \tparam M number of rows in matrix
/// \tparam N number of columns in matrix
template<typename T, unsigned int M, unsigned int N>
class Matrix {

    T m_elem[M][N];

public:
    Matrix()
    {
        // initialize matrix to 0
        memset(&m_elem, 0, sizeof(T)*M*N);
    }

    unsigned int rows() const { return M; }
    unsigned int columns() const { return N; }

};

///
/// \tparam T data type of the operand and product matrices
/// \tparam M number of rows of operand 1 and product matrices
/// \tparam L
/// \tparam N
/// \param a
/// \param b
/// \return
template<typename T, unsigned int M, unsigned int L, unsigned int N>
Matrix<T, M, N>* operator*(const Matrix<T, M, L>& a, const Matrix<T, L, N>& b)
{
    auto* prod = new Matrix<T, M, N>;

    return prod;

}

} // namespace mycorp
#endif //__MATRIX_H__
