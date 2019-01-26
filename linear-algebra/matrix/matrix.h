//
// Created by Chander Raja on 2019-01-24.
//
///


#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cstring>
#include <cmath>
#include <array>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <type_traits>


namespace mycorp {


///
/// \tparam T matrix data type (int, float, double etc)
/// \tparam M number of rows in matrix
/// \tparam N number of columns in matrix
template<typename T, unsigned int M, unsigned int N>
class Matrix {

    std::array<std::array<T, N>, M> m_elem;

public:

    /// \brief default constructor
    Matrix()
        : m_elem({})
    {
    }

    /// \brief copy constructor
    /// \param initializer
    explicit  Matrix(const std::array<std::array<T, N>, M>& initializer)
        : m_elem(initializer)
    {
    }

    /// \brief assignment operator
    /// \param initializer
    /// \return
    Matrix& operator=(const std::array<std::array<T, M>, N>& initializer) { m_elem = initializer;  return *this; }

    /// \return the number of rows in the matrix
    unsigned int rows() const { return M; }

    /// \return the number of columns in the matrix
    unsigned int columns() const { return N; }

    /// \brief index operator
    /// \param a pair of row and column indices into the matrix. if indices are out of bounds,
    /// an out of bound exception is thrown
    /// \return a non-const reference to an element in the matrix
    T& operator[] (const std::pair<unsigned int, unsigned int>& a)
    {
        return m_elem.at(a.first).at(a.second); // use at() instead of [] because it throws out of bound exception
    }

    /// \brief index operator
    /// \param a pair of row and column indices into the matrix. if indices are out of bounds,
    /// an out of bound exception is thrown
    /// \return a const reference to an element in the matrix
    const T& operator[] (const std::pair<unsigned int, unsigned int>& a) const
    {
        return m_elem.at(a.first).at(a.second); // use at() instead of [] because it throws out of bound exception
    }

    /// \brief equal-to comparison operator for floating point types
    /// \param b other matrix to comapre with
    /// \return true if equal to other matrix, false otherwise
    template<typename U = T>
    typename std::enable_if<std::is_integral<U>::value, bool>::type operator==(const Matrix& b) const
    {
        printf("is integer\n");
        for (unsigned int row = 0; row < M; ++row) {
            for (unsigned int col = 0; col < N; ++col) {
                if (m_elem[row][col] != b.m_elem[row][col]) return false;
            }
        }
        return true;
    }

    /// \brief equal-to comparison operator for floating point types
    /// \param b other matrix to comapre with
    /// \return true if equal to other matrix, false otherwise
    template<typename U = T>
    typename std::enable_if<std::is_floating_point<U>::value, bool>::type operator==(const Matrix& b) const
    {
        for (unsigned int row = 0; row < M; ++row) {
            for (unsigned int col = 0; col < N; ++col) {
                T x = m_elem[row][col];
                T y = b.m_elem[row][col];
                T epsilon_factor = std::fmax(std::fabs(x), std::fabs(y));
                bool almost_equal = (std::fabs(x - y) <= std::numeric_limits<T>::epsilon()*epsilon_factor);
                if (!almost_equal) return false;
            }
        }

        return true;
    }

    /// \brief not-equal-to comparison operator
    /// \param b other matrix to comapre with
    /// \return true if not equal to other matrix, false otherwise
    bool operator!=(const Matrix& b) const { return !(*this==b); }

};



/// \brief function to perform matrix multiplication
/// \tparam T data type of the operand and product matrices
/// \tparam M number of rows of operand 1 and product matrices
/// \tparam L number of columns in operand 1 matrix and number of rows in operand 2 matrix
/// \tparam N number of columns in operand 2 and product matrices
/// \param a first operand matrix
/// \param b second operand matrix
/// \return pointer to a newly allocated MxN matrix containing the product of a and b
template<typename T, unsigned int M, unsigned int L, unsigned int N>
Matrix<T, M, N>* operator*(const Matrix<T, M, L>& a, const Matrix<T, L, N>& b)
{
    auto* prod = new Matrix<T, M, N>;

    for (unsigned int row = 0; row < M; ++row) {
        for (unsigned int col = 0; col < N; ++col) {
            for (unsigned int i = 0; i < L; ++i) {
                (*prod)[{row, col}] += (a[{row, i}] * b[{i, col}]);
            }
        }
    }

    return prod;

}

/// \brief function to perform matrix transpose operation
/// \tparam T data type of the operand and product matrices
/// \tparam M number of rows of operand 1 and product matrices
/// \tparam L number of columns in operand 1 matrix and number of rows in operand 2 matrix
/// \tparam N number of columns in operand 2 and product matrices
/// \param a matrix to be transposed
/// \return pointer to a newly allocated NxM matrix containing the transpose of matrix a
template<typename T, unsigned int M, unsigned int N>
Matrix<T, N, M>* transposeMatrix(const Matrix<T, M, N>& a)
{
    auto* transposed = new Matrix<T, N, M>;

    for (unsigned int row = 0; row < M; ++row) {
        for (unsigned int col = 0; col < N; ++col) {
            (*transposed)[{col, row}] = a[{row, col}];
        }
    }

    return transposed;

}


///
/// \tparam T
/// \tparam M
/// \tparam N
/// \param stream
/// \param matrix
/// \return
template<typename T, unsigned int M, unsigned int N>
std::ostream& operator<<(std::ostream& os, const Matrix<T, M, N>& m) {
    for (unsigned int row = 0; row < M; ++row) {
        for (unsigned int col = 0; col < N; ++col) {
            os << m[{row, col}] << "\t";
        }
        os << std::endl;
    }

    return os;

}

} // namespace mycorp

#endif //__MATRIX_H__
