//
// Created by Chander Raja on 2019-01-24.
//
///


#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cstring>
#include <array>
#include <stdexcept>


namespace mycorp {

///
/// \tparam T matrix data type (int, float, double etc)
/// \tparam M number of rows in matrix
/// \tparam N number of columns in matrix
template<typename T, unsigned int M, unsigned int N>
class Matrix {
    /*
public:
    class _proxy
    {
        std::array<T, N> m_column;
    public:
        std::array<T, N>& operator[](int j) { return m_column.at[j]; } // use at() since it throws out of bound exception

    };
     */

private:
    std::array<std::array<T, M>, N> m_elem;

public:

    /// \brief default constructor
    Matrix()
        : m_elem({})
    {
    }

    /// \brief copy constructor
    /// \param initializer
    Matrix(const std::array<std::array<T, M>, N>& initializer)
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

};

///
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


/// \brief Comparison operator
/// \tparam T data type of the operand and product matrices
/// \tparam M number of rows of operand 1 and product matrices
/// \tparam L number of columns in operand 1 matrix and number of rows in operand 2 matrix
/// \tparam N number of columns in operand 2 and product matrices
/// \param a first operand matrix
/// \param b second operand matrix
/// \return pointer to a newly allocated MxN matrix containing the product of a and b
template<typename T, unsigned int M, unsigned int N>
Matrix<T, M, N>* operator==(const Matrix<T, M, N>& a, const Matrix<T, M, N>& b)
{
    for (unsigned int row = 0; row < M; ++row) {
        for (unsigned int col = 0; col < N; ++col) {
            if (a[{row, col}] != b[{row, col}]) return false;
        }
    }

    return true;
}

} // namespace mycorp

#endif //__MATRIX_H__
