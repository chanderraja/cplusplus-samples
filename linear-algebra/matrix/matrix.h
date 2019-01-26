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


namespace LinearAlgebraLib {


///
/// \tparam T matrix data type (int, float, double etc)
/// \tparam M number of rows in matrix
/// \tparam N number of columns in matrix
template<typename T, size_t M, size_t N>
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
    size_t rows() const { return M; }

    /// \return the number of columns in the matrix
    size_t columns() const { return N; }

    /// \brief index operator
    /// \param a pair of row and column indices into the matrix. if indices are out of bounds,
    /// an out of bound exception is thrown
    /// \return a non-const reference to an element in the matrix
    T& operator[] (const std::pair<size_t, size_t>& a)
    {
        return m_elem.at(a.first).at(a.second); // use at() instead of [] because it throws out of bound exception
    }

    /// \brief index operator
    /// \param a pair of row and column indices into the matrix. if indices are out of bounds,
    /// an out of bound exception is thrown
    /// \return a const reference to an element in the matrix
    const T& operator[] (const std::pair<size_t, size_t>& a) const
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
        for (size_t row = 0; row < M; ++row) {
            for (size_t col = 0; col < N; ++col) {
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
        for (size_t row = 0; row < M; ++row) {
            for (size_t col = 0; col < N; ++col) {
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




    /// \brief method to perform matrix multiplication with a NxL matrix
    /// \tparam L number of columns in other operand matrix and product matrix
    /// \param b other operand matrix
    /// \return pointer to a newly allocated MxL matrix containing the product of this matrix and b
    template<size_t L>
    Matrix<T, M, L>* operator*(const Matrix<T, N, L>& b)
    {
        auto* prod = new Matrix<T, M, L>;

        for (size_t row = 0; row < M; ++row) {
            for (size_t col = 0; col < L; ++col) {
                for (size_t i = 0; i < N; ++i) {
                    (*prod)[{row, col}] += (m_elem[row][i] * b[{i, col}]);
                }
            }
        }

        return prod;

    }


    /// \brief method to perform matrix transpose operation
    /// \return pointer to a newly allocated NxM matrix containing the transpose of this matrix
    Matrix<T, N, M>* transpose()
    {
        auto* transposed = new Matrix<T, N, M>;

        for (size_t row = 0; row < M; ++row) {
            for (size_t col = 0; col < N; ++col) {
                (*transposed)[{col, row}] = m_elem[row][col];
            }
        }

        return transposed;
    }


};


///
/// \tparam T
/// \tparam M
/// \tparam N
/// \param stream
/// \param matrix
/// \return
template<typename T, size_t M, size_t N>
std::ostream& operator<<(std::ostream& os, const Matrix<T, M, N>& m) {
    for (size_t row = 0; row < M; ++row) {
        for (size_t col = 0; col < N; ++col) {
            os << m[{row, col}] << "\t";
        }
        os << std::endl;
    }

    return os;

}

} // namespace LinearAlgebraLib

#endif //__MATRIX_H__
